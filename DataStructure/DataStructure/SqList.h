#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50


typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

//建立线性表
void CreateList(SqList*& L, ElemType a[], int n)
{
	int i = 0, k = 0;
	L = (SqList*)malloc(sizeof(SqList));
	while (i < n)
	{
		L->data[k] = a[i];
		k++;
		i++;
	}
	L->length = k;
}

//初始化线性表
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

//销毁线性表
void DestroyList(SqList*& L)
{
	free(L);
}

//判断线性表是否是空表
bool ListEmpty(SqList*& L)
{
	return(L->length == 0);
}

//求线性表的长度
int ListLength(SqList*& L)
{
	return(L->length);
}

//输出线性表
void DisList(SqList*& L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//求线性表中的某个数据元素值
bool GetElem(SqList*& L, int i, ElemType& e)
{
	if (i < 1 || i > L->length)
	{
		return false;
	}
	e = L->data[i - 1];
	return true;
}

//按元素值查找
int LocateElem(SqList*& L, ElemType e)
{
	int i = 0;
	while (i < L->length && L->data[i] != e)
	{
		i++;
	}
	if (i >= L->length)
	{
		return 0;
	}
	else
	{
		return i + 1;
	}
}

//插入数据元素
bool ListInsert(SqList*& L, int i, ElemType e)
{
	int j;
	if (i<1 || i>L->length + 1)
		return false;
	i--;
	for (j = L->length; j > i; j--)
	{
		L->data[j] = L->data[j - 1];
	}
	L->data[i] = e;
	L->length++;
	return true;
}

//删除数据元素
bool ListDelete(SqList*& L, int i, ElemType& e)
{
	int j;
	if (i<1 || i>L->length)
		return false;
	i--;
	e = L->data[i];
	for (j = i; j < L->length - 1; j++)
	{
		L->data[j] = L->data[j + 1];
	}
	L->length--;
	return true;
}