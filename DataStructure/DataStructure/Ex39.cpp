// 将二叉树转单链表

#include<stdio.h>
#include<malloc.h>
#define MaxSize 500


typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

BTNode* firstLeaf;
BTNode* pcur;

void CreateBTree(BTNode* b, char* str)	//创建二叉树
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//建立的二叉树初始时为空
	ch = str[j];
	while (ch != '\0')  	//str未扫描完时循环
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//为左孩子节点
		case ')':top--; break;
		case ',':k = 2; break;                      		//为孩子节点右节点
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 	//*p为二叉树的根节点
				b = p;
			else  								//已建立二叉树根节点
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void Ex39()
{}