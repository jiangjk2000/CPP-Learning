#include <stdio.h>
#include "LinkNode.h"

void RemoveMinMax(ElemType min, ElemType max, LinkNode*& L)
{
	LinkNode* p = L->next, * q = L;
	while (p != NULL)
	{
		if (p->data > min)
		{
			q->next = p->next;
			free(p);
		}
		else if (p->data < max)
		{
			q->next = p->next;
			free(p);
		}
		else
		{
			p = p->next;
			q = q->next;
		}
	}
}

void Ex64()
{

}