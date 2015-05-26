#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
	char data;
	struct node *lchild, *rchild;
}bTree;

bTree *create()
{
	char x;
	bTree *t;
	scanf("%c", &x);
	if (x == '#') 
	    t = NULL;
	else
	{
		t = (bTree *)malloc(sizeof(bTree));
		t->data=x;
		t->lchild=create();
		t->rchild=create();
	}
	return t;
}

void inorder(bTree *t)
{
	if (t == NULL)
		return;
	inorder(t->lchild);
	printf("%c", t->data);
	inorder(t->rchild);
}

void main()
{
	bTree *t;
	puts("input the sequence of the tree: \n");
	t = create();
	puts("the binary tree: \n");
	inorder(t);
	puts("\n");
}