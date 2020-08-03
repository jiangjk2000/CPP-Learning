#include <stdio.h>
#include <malloc.h>

typedef struct tree
{
    int data;
    struct tree* left;
    struct tree* right;
}node, * pnode;

pnode firstLeaf;
pnode pcur;

pnode createTreeNode(int data)
{
    pnode n = (pnode)malloc(sizeof(pnode));
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void inorder(pnode p)
{
    if (NULL == p)
    {
        return;
    }
    inorder(p->left);
    printf("%d  ", p->data);
    inorder(p->right);
}

void leafLink(pnode root)
{
    if (!root)
    {
        return;
    }

    if (NULL == root->left && NULL == root->right)
    {
        if (NULL == firstLeaf)
        {
            firstLeaf = root; // 保存找到的第一个叶子结点（k指针）
            pcur = firstLeaf;
        }
        else
        {
            // 链接时用叶子结点的rchild域存放指针
            pcur->right = root;
            pcur = pcur->right;
        }
    }

    if (root->left)
    {
        leafLink(root->left);
    }

    if (root->right)
    {
        leafLink(root->right);
    }
}

int main()
{
    pnode root = NULL;

    pnode p1 = NULL, p2 = NULL, p3 = NULL, p4 = NULL, p5 = NULL, p6 = NULL, p7 = NULL, p8 = NULL, p9 = NULL;

    p1 = createTreeNode(7);
    p2 = createTreeNode(1);
    p3 = createTreeNode(9);
    p4 = createTreeNode(5);
    p5 = createTreeNode(8);
    p6 = createTreeNode(3);
    p7 = createTreeNode(6);
    p8 = createTreeNode(2);
    p9 = createTreeNode(4);

    p1->left = p2;
    p1->right = p3;

    p2->right = p4;

    p3->left = p5;

    p4->left = p6;
    p4->right = p7;

    p6->left = p8;
    p6->right = p9;

    printf("二叉树中序遍历序列: ");
    root = p1;
    inorder(root);
    printf("\n");

    leafLink(root);
    printf("叶子节点链表 ");
    while (firstLeaf)
    {
        if (firstLeaf->right)
        {
            printf("%d-->", firstLeaf->data);
        }
        else
        {
            printf("%d", firstLeaf->data);
        }
        firstLeaf = firstLeaf->right;
    }
    printf("\n");
}