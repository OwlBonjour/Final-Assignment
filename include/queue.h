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

#ifndef _QUEUE_H
#define _QUEUE_H

void InitQueue(LinkQueue *Q);
void EnQueue(LinkQueue *Q, char e);
int QueueisEmpty(LinkQueue Q);
int QueueLength(LinkQueue Q);
void DeQueue(LinkQueue *Q, char *e);
void GetHead(LinkQueue Q, char *e);
void DestroyQueue(LinkQueue *Q);
void ClearQueue(LinkQueue *Q);

#endif //_QUEUE_H
