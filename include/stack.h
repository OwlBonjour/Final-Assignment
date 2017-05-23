#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;

#ifndef _STACK_H
#define _STACK_H

void InitStack(SqStack *S);
void DestroyStack(SqStack *S);
void ClearStack(SqStack *S);
int StackisEmpty(SqStack S);
int StackLength(SqStack S);
void GetTop(SqStack S, char *e);
void Push(SqStack *S, char e);
void Pop(SqStack *S, char *e);

#endif //_STACK_H
