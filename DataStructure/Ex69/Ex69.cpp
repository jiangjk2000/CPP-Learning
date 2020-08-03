//写在无头结点的单链表的第i个元素之前插入一个元素的程序

#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L = NULL;
}

void Insert(LinkNode*& L, ElemType a, int i)
{
	LinkNode* p = L;
	for (int k = 1; k < i-1; k++)
		p = p->next;
	LinkNode* t = (LinkNode*)malloc(sizeof(LinkNode));
	t->data = a;
	t->next = p->next;
	p->next = t;
}

void CreateListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));  	//创建头结点
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//创建新结点s
		s->data = a[i];
		s->next = L->next;			//将结点s插在原开始结点之前,头结点之后
		L->next = s;
	}
	L = L->next;
}

void DispList(LinkNode* &L)
{
	LinkNode* p = L;

	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}



int main()
{
	LinkNode* a;
	InitList(a);
	int b[5] = { 3,5,6,4,8 };
	CreateListF(a, b, 5); DispList(a);
	Insert(a, 99, 3); DispList(a);
}