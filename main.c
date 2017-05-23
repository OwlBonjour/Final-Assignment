#include <stdio.h>
#include "include/queue.h"
#include "include/stack.h"
#include "include/tree.h"

void _TEST_STACK_(void);
void _TEST_QUEUE_(void);
void _TEST_BITREE_(void);
int main(void) {
	_TEST_STACK_();
	_TEST_QUEUE_();
	_TEST_BITREE_();
	return 0;
}

void _TEST_QUEUE_(void) {
	printf("\n******** 开始测试 queue.c 中的函数。********\n\n");
	LinkQueue q;
	InitQueue(&q); // TEST InitStack
	printf("测试 InitQueue(LinkQueue *Q)：队列初始化完成。\n");
	printf("\n******** 测试完了 queue.c 中的函数。********\n\n");
}

void _TEST_STACK_(void) {
	// TEST stack.h begin
	printf("\n******** 开始测试 stack.c 中的函数。********\n\n");
	SqStack s;
	InitStack(&s); // TEST InitStack
	printf("测试 InitStack(SqStack *S)：栈初始化完成。\n");
	if (StackisEmpty(s)) {
		printf("测试 StackisEmpty(SqStack S)：");
		printf("刚初始化好的栈是空的。\n");
	}
	// TEST Push & StackLength
	Push(&s, 'a'); Push(&s, 'b'); Push(&s, 'c');
	printf("测试 StackLength(SqStack S)：Push 'a', 'b', 'c'后，");
	printf("栈长 = %d\n", StackLength(s));
	printf("测试 Push(SqStack *S, char e)：\n\tPush(&s, 'a');\n\tPush(&s, 'b');\n\tPush(&s, 'c');\n");
	// TEST Pop & GetTop
	char ch = 'z';
	GetTop(s, &ch);
	printf("测试 GetTop(SqStack S, char *ch)：\n\tGetTop(s, &ch);\t用 GetTop 查看栈顶，是：%c\n", ch);
	printf("测试 Pop(SqStack *S, char *ch)：\n\tPop(&s, &ch);\tPop 出的元素是：%c\n", ch);
	// TEST ClearStack
	ClearStack(&s);
	printf("测试 ClearStack(SqStack *S)：\n\tClearStack(&s);\tClearStack 后，栈长 = %d\n", StackLength(s));
	// TEST stack.c done
	printf("\n******** 测试完了 stack.c 中的函数。********\n\n");
}
