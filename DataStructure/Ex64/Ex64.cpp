#include <stdio.h>
#include "LinkNode.h"

void RemoveMinMax(ElemType min, ElemType max, LinkNode*& L)
{
    LinkNode* p = L->next;
    LinkNode* q = L;
    while (p != NULL)
    {
        if (p->data > min && p->data < max)
        {
            q->next = p->next;
            p = p->next;
        }
        else
        {
            p = p->next;
            q = q->next;
        }

    }
}

int main()
{
    LinkNode* a;
    InitList(a);
    ElemType b[6] = { 1,9,6,5,4,7 };
    CreateListR(a, b, 6);
    DispList(a);
    RemoveMinMax(4, 7, a);
    DispList(a);
}