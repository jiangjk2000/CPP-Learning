#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef int ElemType;

typedef struct linknode
{
	ElemType data;
	struct linknode* next;
}LinkStNode;

//初始化栈
void InitStack(LinkStNode*& s)
{
	s = (LinkStNode*)malloc(sizeof(LinkStNode));
	s->next = NULL;
}

//销毁栈
void DestoryStack(LinkStNode*& s)
{
	LinkStNode* pre = s, * p = s->next;
	while (p != NULL)
	{
		free(pre);
		pre = p;
		p = pre->next;
	}
	free(pre);
}

//判断是否为空
bool StackEmpty(LinkStNode* s)
{
	return(s->next == NULL);
}

//进栈Push
void Push(LinkStNode*& s, ElemType e)
{
	LinkStNode* p;
	p = (LinkStNode*)malloc(sizeof(LinkStNode));
	p->data = e;
	p->next = s->next;
	s->next = p;
}

//出栈Pop
bool Pop(LinkStNode*& s, ElemType& e)
{
	LinkStNode* p;
	if (s->next == NULL)
	{
		return false;
	}
	p = s->next;
	e = p->data;
	s->next = p->next;
	free(p);
	return true;
}

//取栈顶元素
bool GetTop(LinkStNode* s, ElemType& e)
{
	if (s->next == NULL)
	{
		return false;
	}
	e = s->next->data;
	return true;
}