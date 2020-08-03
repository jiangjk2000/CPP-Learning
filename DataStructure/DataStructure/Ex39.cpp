// ��������ת������

#include<stdio.h>
#include<malloc.h>
#define MaxSize 500


typedef char ElemType;
typedef ElemType SqBinTree[MaxSize];

typedef struct node
{
	ElemType data;
	struct node* lchild;
	struct node* rchild;
}BTNode;

BTNode* firstLeaf;
BTNode* pcur;

void CreateBTree(BTNode* b, char* str)	//����������
{
	BTNode* St[MaxSize], * p = NULL;
	int top = -1, k, j = 0;
	char ch;
	b = NULL;				//�����Ķ�������ʼʱΪ��
	ch = str[j];
	while (ch != '\0')  	//strδɨ����ʱѭ��
	{
		switch (ch)
		{
		case '(':top++; St[top] = p; k = 1; break;		//Ϊ���ӽڵ�
		case ')':top--; break;
		case ',':k = 2; break;                      		//Ϊ���ӽڵ��ҽڵ�
		default:p = (BTNode*)malloc(sizeof(BTNode));
			p->data = ch; p->lchild = p->rchild = NULL;
			if (b == NULL)                    	 	//*pΪ�������ĸ��ڵ�
				b = p;
			else  								//�ѽ������������ڵ�
			{
				switch (k)
				{
				case 1:St[top]->lchild = p; break;
				case 2:St[top]->rchild = p; break;
				}
			}
		}
		j++;
		ch = str[j];
	}
}

void Ex39()
{}