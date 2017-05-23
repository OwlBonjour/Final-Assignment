#include "include/queue.h"
#include <stdlib.h>

#define QUEUE_INIT_SIZE 100
#define QUEUEINCREMENT 10

typedef struct QNode {
	char data;
	struct QNode *next;
}QNode;
typedef struct {
	QNode *front, *rear;
	int queuesize;
}LinkQueue;

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
