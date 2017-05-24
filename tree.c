#include "include/tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char str[50] = "AB C  D  \0", str1[50], str2[50];
static char *pstr = str, *pstr1 = str1, *pstr2 = str2;

Status Visit(char e) {
	printf("%c ", e);
	return OK;
}

BiTNode *CreateBiTree() {
	BiTree T;
	char ch = *pstr++;
	if(ch == ' ') T = NULL;
	else {
		if (!(T = (BiTNode *)malloc(sizeof(BiTNode)))) exit(OVERFLOW);
		T->data = ch;
		T->RTag = T->LTag = Link;
		if (T->lchild = CreateBiTree()) T->lchild->parent = T;
		if (T->rchild = CreateBiTree()) T->rchild->parent = T;
	}
	return T;
}

Status PreOrderTraverse_Recursion(BiTree T) {
	if (T) {
		if (Visit(T->data))
			if (PreOrderTraverse_Recursion(T->lchild))
				if (PreOrderTraverse_Recursion(T->rchild)) return OK;
			return ERROR;
	}
	else return OK;
}

void _TEST_TREE_(void) {
	printf("\n*************** 开始测试 tree.c 中的函数。 ***************\n\n");
	// TEST BiTNode *CreateBiTree()
	BiTree T;
	T = CreateBiTree();
	printf("* 测试 BiTNode *CreateBiTree()：\n\tT = CreateBiTree();\n\t【二叉树先序输入：AB(blank)C(blank)(blank)D(blank)(blank)】\n");

	//TEST PreOrderTraverse_Recursion()
	printf("* 测试 PreOrderTraverse_Recursion(BiTree T)：\n\tPreOrderTraverse_Recursion(T);\t\n");
	PreOrderTraverse_Recursion(T);

	// TEST tree.c done
	printf("\n\n*************** 测试完了 tree.c 中的函数。 ***************\n\n");
}
