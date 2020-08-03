#include<malloc.h>
#include<stdio.h>

typedef int ElemType;
typedef struct LNode
{
	ElemType data;
	struct LNode* next;
}LinkNode;     //建立单个单链表结点

void CreateListR(LinkNode*& L, ElemType a[], int n)
//尾插法建立单链表
{
	LinkNode* s, * r;
	L = (LinkNode*)malloc(sizeof(LinkNode));  	//创建头结点
	L->next = NULL;
	r = L;					//r始终指向终端结点,开始时指向头结点
	for (int i = 0; i < n; i++)
	{
		s = (LinkNode*)malloc(sizeof(LinkNode));//创建新结点s
		s->data = a[i];
		r->next = s;			//将结点s插入结点r之后
		r = s;
	}
	r->next = NULL;			//终端结点next域置为NULL
}
void DispList(LinkNode* L)
{
	LinkNode* p = L->next;
	while (p != NULL)
	{
		printf("%d ", p->data);
		p = p->next;
	}
	printf("\n");
}
void Delete(LinkNode*& L, ElemType e)
{
	LinkNode* p, * q;
	p = L->next;
	q = L;
	int b = 0;
	while (p != NULL)
	{
		if (p->data == e)
		{
			q->next = p->next;
			p = p->next;
			b++;
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
	if (b == 0)
	{
		printf("打印信息出错.");
	}
}

int main()
{
	LinkNode* f;
	int a[10] = { 1,2,3,4,5,6,2,8,9,10 };
	CreateListR(f, a, 10);
	DispList(f);
	Delete(f, 1);
	DispList(f);
}