#include "include/queue.h"
#include <stdio.h>
#include <stdlib.h>

void InitQueue(LinkQueue *Q) {
	Q->rear = Q->front = (QNode *)malloc(sizeof(QNode));
	Q->front->next = NULL;
	Q->queuesize = 0;
}

void EnQueue(LinkQueue *Q, char e) {
	QNode *p = (QNode *)malloc(sizeof(QNode));
	p->data = e; p->next = NULL;
	Q->rear->next = p;
	Q->rear = p;
	Q->queuesize++;
}

int QueueisEmpty(LinkQueue Q) {
	if (Q.front->next == NULL) return 1;
	else return 0;
}

int QueueLength(LinkQueue Q) {
	int i;
	QNode *p = Q.front;
	for (i = 0; p->next != NULL; i++) {
		p = p->next;
	}
	return i;
}

void DeQueue(LinkQueue *Q, char *e) {
	if (Q->front == Q->rear) return;
	QNode *p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p) Q->rear = Q->front;
	free(p);
}

void GetHead(LinkQueue Q, char *e) {
	if (QueueisEmpty(Q)) return;
	else *e = Q.front->next->data;
}

void DestroyQueue(LinkQueue *Q) {
	Q->queuesize = 0;
	while (Q->front) {
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
}

void ClearQueue(LinkQueue *Q) {
	DestroyQueue(Q);
	InitQueue(Q);
}


/* TEST FUNCTION */
void _TEST_QUEUE_(void) {
	printf("\n*************** 开始测试 queue.c 中的函数。***************\n\n");
	LinkQueue q;
	InitQueue(&q); // TEST InitStack
	printf("* 测试 InitQueue(LinkQueue *Q)：\n\t队列初始化完成。\n");
	if (QueueisEmpty(q)) {
		printf("* 测试 QueueisEmpty(LinkQueue Q)：\n\t");
		printf("刚初始化好的队列是空的。\n");
	}

	// TEST EnQueue & QueueLength
	printf("* 测试 EnQueue(LinkQueue *Q, char e)：\n\tEnQueue(&q, 'a');\n\tEnQueue(&q, 'b');\n\tEnQueue(&q, 'c');\n");
	EnQueue(&q, 'a'); EnQueue(&q, 'b'); EnQueue(&q, 'c');
	printf("* 测试 QueueLength(LinkQueue Q)：\n\tEnQueue 'a', 'b', 'c'后，");
	printf("队列长 = %d\n", QueueLength(q));

	// TEST DeQueue & GetHead
	char ch = 'z';
	GetHead(q, &ch);
	printf("* 测试 GetHead(LinkQueue Q, char *e)：\n\tGetHead(q, &ch);\t用 GetHead 查看队列头，是：%c\n", ch);
	DeQueue(&q, &ch); DeQueue(&q, &ch);
	printf("* 测试 DeQueue(LinkQueue *Q, char *e)：\n\tDeQueue(&q, &ch);\tDeQueue 两次出的元素是：%c\n", ch);

	// TEST ClearQueue
	ClearQueue(&q);
	printf("* 测试 ClearQueue(LinkQueue *Q)：\n\tClearQueue(&q);\tClearStack 后，队列长 = %d\n", QueueLength(q));

	// TEST queue.c done
	printf("\n*************** 测试完了 queue.c 中的函数。***************\n\n");
}
