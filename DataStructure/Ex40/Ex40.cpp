// Ex40.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include<stdio.h>
#include<malloc.h>
#include "btree.h"
typedef int ElemType;                    //数据类型

typedef struct BiTreeNode                //二叉树结构体
{
	ElemType date;                        //结点数据
	struct BiTreeNode* lChild;            //左指针
	int lFlag;                            //左标记（==0时，左指针存储左孩子结点；==1时，左指针存储前驱结点）
	struct BiTreeNode* rChild;            //右指针
	int rFlag;                            //右标记（==0时，右指针存储右孩子结点；==1时，右指针存储后继结点）
}*BiTree;
BiTree pre;

typedef struct QNode                    //结点结构体
{
	BiTree date;                        //结点数据
	struct QNode* next;                    //结点指针
}*LinkQuePtr;                            //结点名

typedef struct
{
	BTNode* data[MaxSize];			//存放栈中的数据元素
	int top;						//存放栈顶指针，即栈顶元素在data数组中的下标
} SqStack;							//顺序栈类型

void InitStack(SqStack*& s)			//初始化栈
{
	s = (SqStack*)malloc(sizeof(SqStack));//分配一个是顺序栈空间，首地址存放在s中
	s->top = -1;						//栈顶指针置为-1
}
void DestroyStack(SqStack*& s)		//销毁栈
{
	free(s);
}
bool StackEmpty(SqStack* s)			//判断栈是否为空
{
	return(s->top == -1);
}
bool Push(SqStack*& s, BTNode* e)	//进栈
{
	if (s->top == MaxSize - 1)			//栈满的情况，即栈上溢出
		return false;
	s->top++;						//栈顶指针增1
	s->data[s->top] = e;				//元素e放在栈顶指针处
	return true;
}
bool Pop(SqStack*& s, BTNode*& e)	//出栈
{
	if (s->top == -1)					//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];				//取栈顶指针元素的元素
	s->top--;						//栈顶指针减1
	return true;
}
bool GetTop(SqStack* s, BTNode*& e)	//取栈顶元素
{
	if (s->top == -1)					//栈为空的情况，即栈下溢出
		return false;
	e = s->data[s->top];				//取栈顶元素
	return true;
}


int Depth(BiTree T)
{
	if (T == NULL)                        //如果当前结点为空，返回0
		return 0;
	int L = Depth(T->lChild);            //遍历左子树
	int R = Depth(T->rChild);            //遍历右子树
	if (L > R)                            //取最大值返回
		return (L + 1);
	else
		return (R + 1);
}

void Depth2(BTNode* b)			//先序非递归遍历算法2
{
	int n;
	BTNode* p;
	SqStack* st;					//定义一个顺序栈指针st
	InitStack(st);					//初始化栈st
	p = b;
	while (!StackEmpty(st) || p != NULL)
	{
		while (p != NULL)				//访问节点p及其所有左下节点并进栈
		{
			n++;
			Push(st, p);				//节点p进栈
			p = p->lchild;			//移动到左孩子
		}
		if (!StackEmpty(st))		//若栈不空
		{
			Pop(st, p);				//出栈节点p
			p = p->rchild;			//转向处理其右子树
		}
	}
	DestroyStack(st);				//销毁栈
}

void CreatBiTree(BiTree* T)
{
	ElemType e;                        //结点数据
	scanf_s("%d", &e);
	if (e == -1)                        //如果输入为-1，当前结点为空
		(*T) = NULL;
	else
	{
		(*T) = (BiTree)malloc(sizeof(BiTreeNode));        //申请结点空间
		(*T)->date = e;                        //为当前结点赋值
		printf("请输入当前结点 %d 的左孩子，若没有左孩子，请输入-1\n", e);
		CreatBiTree(&((*T)->lChild));        //递归创建左子树
		printf("请输入当前结点 %d 的右孩子，若没有右孩子，请输入-1\n", e);
		CreatBiTree(&((*T)->rChild));        //递归创建右子树
	}
}

int main()
{
	BiTree T;
	int dep = 0;
	T = NULL;
	CreatBiTree(&T);
    printf("%d ", Depth(T));
}

