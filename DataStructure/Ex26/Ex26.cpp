#include <stdio.h>
#include <malloc.h>
typedef struct snode
{
	char data;
	struct snode* next;
} LinkStrNode;

int StrLength(LinkStrNode* s)	//求串长
{
	int i = 0;
	LinkStrNode* p = s->next;
	while (p != NULL)
	{
		i++;
		p = p->next;
	}
	return i;
}

LinkStrNode* RepStr(LinkStrNode* s, int i, int j, LinkStrNode* t)	//串替换
{
	int k;
	LinkStrNode* str, * p = s->next, * p1 = t->next, * q, * r;
	str = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	str->next = NULL;
	r = str;							//r指向新建链表的尾结点
	if (i <= 0 || i > StrLength(s) || j<0 || i + j - 1>StrLength(s))
		return str;		 			//参数不正确时返回空串
	for (k = 0; k < i - 1; k++)  			//将s的前i-1个结点复制到str
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data; q->next = NULL;
		r->next = q; r = q;
		p = p->next;
	}
	for (k = 0; k < j; k++)				//让p沿next跳j个结点
		p = p->next;
	while (p1 != NULL)				//将t的所有结点复制到str
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p1->data; q->next = NULL;
		r->next = q; r = q;
		p1 = p1->next;
	}
	while (p != NULL)					//将结点p及其后的结点复制到str
	{
		q = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		q->data = p->data; q->next = NULL;
		r->next = q; r = q;
		p = p->next;
	}
	r->next = NULL;
	return str;
}

void DispStr(LinkStrNode* s)	//输出串
{
	LinkStrNode* p = s->next;
	while (p != NULL)
	{
		printf("%c", p->data);
		p = p->next;
	}
	printf("\n");
}

void StrAssign(LinkStrNode*& s, char cstr[], int n)	//字符串常量cstr赋给串s
{
	int i;
	LinkStrNode* r, * p;
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = s;						//r始终指向尾结点
	for (i = 0; i < n; i++)
	{
		p = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		p->data = cstr[i];
		r->next = p; r = p;
	}
	r->next = NULL;
}

void StrAssignN(LinkStrNode*& s, char cstr[], int n)	//字符串常量cstr赋给串s
{
	int i;
	LinkStrNode* r, * p;
	s = (LinkStrNode*)malloc(sizeof(LinkStrNode));
	r = s;						//r始终指向尾结点
	for (i = n; i > 0; i--)
	{
		p = (LinkStrNode*)malloc(sizeof(LinkStrNode));
		p->data = cstr[i-1];
		r->next = p; r = p;
	}
	r->next = NULL;
}

int main()
{
	LinkStrNode* c, * d, * e;
	char a[3] = { 'a','b','c' }, b[5] = { 'a','b','c','d','e' };
	StrAssign(c, a, 3);
	StrAssign(d, b, 5);
	StrAssignN(e, a, 3);
	DispStr(c);
	DispStr(d);
	DispStr(e);
	RepStr(d, 1, 3, e);
	DispStr(d);

}