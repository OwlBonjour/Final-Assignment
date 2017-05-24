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

#ifndef _TREE_H
#define _TREE_H

Status Visit(char e);
BiTNode *CreateBiTree();
Status PreOrderTraverse_Recursion(BiTree T);
void _TEST_TREE_(void);

#endif //_TREE_H
