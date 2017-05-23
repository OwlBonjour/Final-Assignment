#include "include/tree.h"
#include <stdlib.h>
#include <string.h>
#define	TRUE		1
#define	FALSE		0
#define	OK		1
#define	ERROR		0
#define	OVERFLOW	-2
#define	Status		int
#define	PointerTag	int
#define	Link		0
#define	Thread		1

typedef struct BiTNode {
	char data;
	struct BiTNode *lchild, *rchild, *parent;
	PointerTag LTag, RTag;
}BiTNode, *BiTree;

Status Visit(char e) {
	printf("%c ", e);
	return OK;
}

char str[50], str1[50], str2[50];
char *pstr = str, *pstr1 = str1, *pstr2 = str2;

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
	}else return OK;
}
