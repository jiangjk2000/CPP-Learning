#include <stdio.h>
#include <stdlib.h>

#define MaxSize 100

typedef char ElemType;

typedef struct
{
	ElemType data[MaxSize];
	int top;
}SqStack;

typedef struct
{
	ElemType data[MaxSize];
	int top1, top2;
};

//初始化栈
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

//销毁栈
void DestoryStack(SqStack*& s)
{
	free(s);
}

//判断栈是否空
bool StackEmpty(SqStack* s)
{
	return s->top == -1;
}

//进栈Push
bool Push(SqStack*& s, ElemType e)
{
	if (s->top == -1)
	{
		return false;
	}
	s->top++;
	s->data[s->top] = e;
	return true;
}

//出栈Pop
bool Pop(SqStack*& s, ElemType& e)
{
	if (s->top == -1)
	{
		return false;
	}
	e = s->data[s->top];
	s->top--;
	return true;
}

//取栈顶元素
bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
	{
		return false;
	}
	e = s->data[s->top];
	return true;
}