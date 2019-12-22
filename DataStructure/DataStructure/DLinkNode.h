#include <stdio.h>
#include <stdlib.h>

typedef int ElemType;

typedef struct DNode
{
	ElemType data;
	struct DNode* prior;
	struct DNode* next;
}DLinkNode;

//头插法建立双链表
void CreatListF(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->prior = L->next = NULL;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		s->next = L->next;
		if (L->next != NULL)
		{
			L->next->prior = s;
		}
		L->next = s;
		s->prior = L;
	}
}

//尾插法建立双链表
void CreatListR(DLinkNode*& L, ElemType a[], int n)
{
	DLinkNode* s, * r;
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	r = L;
	for (int i = 0; i < n; i++)
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = a[i];
		r->next = s;
		s->prior = r;
		r = s;
	}
	r->next = NULL;
}

//双链表插入元素
bool ListInsert(DLinkNode*& L, int i, ElemType e)
{
	int j = 0;
	DLinkNode* p = L, * s;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		s = (DLinkNode*)malloc(sizeof(DLinkNode));
		s->data = e;
		s->next = p->next;
		if (p->next != NULL)
		{
			p->next->prior = s;
		}
		s->prior = p;
		p->next = s;
		return true;
	}
}

//双链表删除元素
bool ListDelete(DLinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	DLinkNode* p = L, * q;
	if (i <= 0) return false;
	while (j < i - 1 && p != NULL)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		q = p->next;
		if (q == NULL)
		{
			return false;
		}
		e = q->data;
		p->next = q->next;
		if (p->next != NULL)
		{
			p->next->prior = p;
		}
		free(q);
		return false;
	}
}

//与单链表相同
//初始化线性表
void InitList(DLinkNode*& L)
{
	L = (DLinkNode*)malloc(sizeof(DLinkNode));
	L->next = NULL;
}

//销毁线性表
void DestroyList(DLinkNode*& L)
{
	DLinkNode* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

//判断线性表是否是为空表
bool ListEmpty(DLinkNode*& L)
{
	return(L->next == NULL);
}

//求线性表的长度
int ListLength(DLinkNode*& L)
{
	int n = 0;
	DLinkNode* p = L;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//输出线性表
void DispList(DLinkNode*& L)
{
	DLinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}

//求线性表中的某个数据元素值
bool GetElem(DLinkNode*& L, int i, ElemType& e)
{
	int j = 0;
	DLinkNode* p = L;
	if (i <= 0) return false;
	while (true)
	{
		j++;
		p = p->next;
	}
	if (p == NULL)
	{
		return false;
	}
	else
	{
		e = p->data;
		return true;
	}
}