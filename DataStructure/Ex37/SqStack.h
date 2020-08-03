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

//��ʼ��ջ
void InitStack(SqStack*& s)
{
	s = (SqStack*)malloc(sizeof(SqStack));
	s->top = -1;
}

//����ջ
void DestoryStack(SqStack*& s)
{
	free(s);
}

//�ж�ջ�Ƿ��
bool StackEmpty(SqStack* s)
{
	return s->top == -1;
}

//��ջPush
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

//��ջPop
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

//ȡջ��Ԫ��
bool GetTop(SqStack* s, ElemType& e)
{
	if (s->top == -1)
	{
		return false;
	}
	e = s->data[s->top];
	return true;
}