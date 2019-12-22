#include <stdio.h>
#include <stdlib.h>
#define MaxSize 50


typedef int ElemType;
typedef struct
{
	ElemType data[MaxSize];
	int length;
}SqList;

//�������Ա�
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

//��ʼ�����Ա�
void InitList(SqList*& L)
{
	L = (SqList*)malloc(sizeof(SqList));
	L->length = 0;
}

//�������Ա�
void DestroyList(SqList*& L)
{
	free(L);
}

//�ж����Ա��Ƿ��ǿձ�
bool ListEmpty(SqList*& L)
{
	return(L->length == 0);
}

//�����Ա�ĳ���
int ListLength(SqList*& L)
{
	return(L->length);
}

//������Ա�
void DisList(SqList*& L)
{
	for (int i = 0; i < L->length; i++)
	{
		printf("%d ", L->data[i]);
	}
	printf("\n");
}

//�����Ա��е�ĳ������Ԫ��ֵ
bool GetElem(SqList*& L, int i, ElemType& e)
{
	if (i < 1 || i > L->length)
	{
		return false;
	}
	e = L->data[i - 1];
	return true;
}

//��Ԫ��ֵ����
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

//��������Ԫ��
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

//ɾ������Ԫ��
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