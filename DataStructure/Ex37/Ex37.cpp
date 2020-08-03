// 给定一棵二叉树用链表表示，用非递归算法求出二叉树结点的数目

#include <stdio.h>
#include <stdlib.h>
#include "LinkNode.h"
#include "SqStack.h"
#include "BTree.h"

// 递归算法
int CountLeaf(BTNode* b)
{
	int num = 0;
	if (b != NULL)
	{
		if (b->lchild == NULL && b->rchild == NULL)
		{
			num++;
		}
		CountLeaf(b->lchild);
		CountLeaf(b->rchild);
	}
	return num;
}


int main()
{
	BTNode* a;
	char b[] = { "A(B,D)" };
	CreateBTree(a, b);
	printf("num:%d ", CountLeaf(a));
	return 0;
}