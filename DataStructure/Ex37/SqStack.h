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

//³õÊ¼»¯Õ»
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

//Ïú»ÙÕ»
void DestoryStack(SqStack*& s)
{
	free(s);
}

//ÅÐ¶ÏÕ»ÊÇ·ñ¿Õ
bool StackEmpty(SqStack* s)
{
	return s->top == -1;
}

//½øÕ»Push
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

//³öÕ»Pop
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

//È¡Õ»¶¥ÔªËØ
bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
	{
		return false;
	}
	e = s->data[s->top];
	return true;
}