#include "include/stack.h"
#include <stdio.h>
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

/* TEST FUNCTION */
void _TEST_STACK_(void) {
	// TEST stack.h begin
	printf("\n*************** 开始测试 stack.c 中的函数。***************\n\n");
	SqStack s;
	InitStack(&s); // TEST InitStack
	printf("* 测试 InitStack(SqStack *S)：\n\t栈初始化完成。\n");
	if (StackisEmpty(s)) {
		printf("* 测试 StackisEmpty(SqStack S)：\n\t");
		printf("刚初始化好的栈是空的。\n");
	}

	// TEST Push & StackLength
	printf("* 测试 Push(SqStack *S, char e)：\n\tPush(&s, 'a');\n\tPush(&s, 'b');\n\tPush(&s, 'c');\n");
	Push(&s, 'a'); Push(&s, 'b'); Push(&s, 'c');
	printf("* 测试 StackLength(SqStack S)：\n\tPush 'a', 'b', 'c'后，");
	printf("栈长 = %d\n", StackLength(s));

	// TEST Pop & GetTop
	char ch = 'z';
	GetTop(s, &ch);
	printf("* 测试 GetTop(SqStack S, char *ch)：\n\tGetTop(s, &ch);\t用 GetTop 查看栈顶，是：%c\n", ch);
	Pop(&s, &ch);
	printf("* 测试 Pop(SqStack *S, char *ch)：\n\tPop(&s, &ch);\tPop 出的元素是：%c\n", ch);

	// TEST ClearStack
	ClearStack(&s);
	printf("* 测试 ClearStack(SqStack *S)：\n\tClearStack(&s);\tClearStack 后，栈长 = %d\n", StackLength(s));

	// TEST stack.c done
	printf("\n*************** 测试完了 stack.c 中的函数。***************\n\n");
}
