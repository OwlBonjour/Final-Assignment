#include "include/stack.h"
#include <stdlib.h>

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

int StackisEmpty(SqStack S) {
	if (S.top == S.base) return 1;
	else return 0;
}

int StackLength(SqStack S) {
	if (StackisEmpty(S)) return 0;
	else return (S.top - S.base);
}

void GetTop(SqStack S, char *e) {
	if (StackisEmpty(S)) return;
	else *e = *(S.top - 1);
}

void Push(SqStack *S, char e) {
	if (StackLength(*S) >= S->stacksize) {
		S->base = (char *)realloc(S->base, (S->stacksize + STACKINCREMENT) * sizeof(char));
		S->top = S->base + S->stacksize;
		S->stacksize += STACKINCREMENT;
	}
	*(S->top++) = e;
}

void Pop(SqStack *S, char *e) {
	if (StackisEmpty(*S)) return;
	*e = *(--S->top);
}
