#include <stdio.h>
#include <stdlib.h>

typedef char ElemType2;

typedef struct LNode
{
	ElemType2 data;
	struct LNode* next;
}LinkNode;

//建立单链表-头插法
void CreateListF(LinkNode*& L, ElemType2 a[], int n)
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
void CreateListR(LinkNode*& L, ElemType2 a[], int n)
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

//销毁线性表
void DestroyList(LinkNode*& L)
{
	LinkNode* pre = L, * p = L->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

//判断线性表是否是为空表
bool ListEmpty(LinkNode*& L)
{
	return(L->next == NULL);
}

//求线性表的长度
int ListLength(LinkNode*& L)
{
	int n = 0;
	LinkNode* p = L;
	while (p->next != NULL)
	{
		n++;
		p = p->next;
	}
	return n;
}

//输出线性表
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

//求线性表中的某个数据元素值
bool GetElem(LinkNode*& L, int i, ElemType2& e)
{
	int j = 0;
	LinkNode* p = L;
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

//按算法值查找
int LocateElem(LinkNode*& L, ElemType2 e)
{
	int i = 1;
	LinkNode* p = L->next;
	while (p != NULL && p->data != e)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
	{
		return 0;
	}
	else
	{
		return i;
	}
}

//插入数据元素
bool ListInsert(LinkNode*& L, int i, ElemType2 e)
{
	int j = 0;
	LinkNode* p = L, * s;
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
		s = (LinkNode*)malloc(sizeof(LinkNode));
		s->data = e;
		s->next = p->next;
		p->next = s;
		return true;
	}
}

//删除数据元素
bool ListDelete(LinkNode*& L, int i, ElemType2& e)
{
	int j = 0;
	LinkNode* p = L, * q;
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
		free(q);
		return true;
	}
}