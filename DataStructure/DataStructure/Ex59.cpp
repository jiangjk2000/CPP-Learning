#include <stdio.h>
#include <stdlib.h>
#define MaxSize 1000

typedef int ElemType;

typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;

//建立单链表-头插法
void CreateListF(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		s->next = L->next;
		L->next = s;
	}
}

//建立单链表-尾插法
void CreateListR(LinkNode*& L, ElemType a[], int n)
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = a[i];
		r->next = s;
		r = s;
	}
	r->next = NULL;
}

//初始化线性表
void InitList(LinkNode*& L)
{
	L = (LinkNode*)malloc(sizeof(LinkNode));
	L->next = NULL;
}

//二路归并:采用单链表实现
void UnionList(LinkNode* LA, LinkNode* LB, LinkNode*& LC)
{
	LinkNode* pa = LA->next, * pb = LB->next, * pc, * s;
	LC = (LinkNode*)malloc(sizeof(LinkNode));		//创建LC的头结点
	pc = LC;							//pc始终指向LC的最后一个结点
	while (pa != NULL && pb != NULL)
	{
		if (pa->data < pb->data)
		{
			s = (LinkNode*)malloc(sizeof(LinkNode));//复制pa结点
			s->data = pa->data;
			pc->next = s; pc = s;		//采用尾插法将结点s插入到LC的最后
			pa = pa->next;
		}
		else
		{
			s = (LinkNode*)malloc(sizeof(LinkNode));//复制pb结点
			s->data = pb->data;
			pc->next = s; pc = s;		//采用尾插法将结点s插入到LC的最后
			pb = pb->next;
		}
	}
	while (pa != NULL)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));	//复制pa结点
		s->data = pa->data;
		pc->next = s; pc = s;		//采用尾插法将结点s插入到LC的最后
		pa = pa->next;
	}
	while (pb != NULL)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));	//复制pa结点
		s->data = pb->data;
		pc->next = s; pc = s;		//采用尾插法将结点s插入到LC的最后
		pb = pb->next;
	}
	pc->next = NULL;
}

bool ListEmpty(LinkNode*& L)
{
	return(L->next == NULL);
}

void DispList(LinkNode*& L)
{
	LinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

LinkNode mergeKLists(LinkNode[MaxSize] lists, int n)
{
	if (n == 0)
		return NULL;
	LinkNode head = lists[0];
	for (int i = 1; i < lists.length; i++) {
		head = UnionList(head, lists[i]);
	}
	return head;
}


void Ex59()
{
	LinkNode *LA[MaxSize], *LB, *LC;
	InitList(LA[0]);
	InitList(LA[1]);
	InitList(LA[2]);
	InitList(LB);
	InitList(LC);
	ElemType a[] = { 1,3,5 };
	ElemType b[] = { 2,4,8,10 };
	ElemType c[] = { 4,5,6,7,8 };
	CreateListR(LA[0], a, 3);
	CreateListR(LA[1], b, 4);
	CreateListR(LA[2], c, 5);
	//printf("LA[0]:"); DispList(LA[0]);
	//printf("LA[1]:"); DispList(LA[1]);
	//printf("LA[2]:"); DispList(LA[2]);
	
	ListEmpty(LA[3]);

	LB = LA[0];
	for (int i = 1; !ListEmpty(LA[i]); i++)
	{
		UnionList(LA[i], LB, LC);
		LB = LC;
	}
	DispList(LC);
	
}
