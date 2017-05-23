#include "include/stack.h"
#include <stdlib.h>

#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef struct {
	char *base;
	char *top;
	int stacksize;
}SqStack;

void InitStack(SqStack *S) {
	S->base = (char *)malloc(STACK_INIT_SIZE * sizeof(char));
	S->top = S->base;
	S->stacksize = STACK_INIT_SIZE;
}

void DestroyStack(SqStack *S) {
	S->top = NULL;
	S->stacksize = 0;
	free(S->base);
}

void ClearStack(SqStack *S) {
	S->top = S->base;
}

int StackisEmpty(SqStack *S) {
	if (S->top == S->base) return 1;
	else return 0;
}

int StackLength(SqStack *S) {
	if (S->top == S->base) return 0;
	else return (S->top - S->base);
}

void GetTop(SqStack *S, char *e) {
	if (S.top == S.base) return;
	else e = *(S->top);
}

void Push(SqStack *S) {}

void Pop(SqStack *S) {}

void StackTraverse(SqStack *S) {}
