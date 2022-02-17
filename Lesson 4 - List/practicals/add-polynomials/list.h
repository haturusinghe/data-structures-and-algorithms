#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ListEntry;
typedef int Position;

typedef struct listnode
{
    ListEntry coeff;
    ListEntry expo;
    struct listnode *next;
}ListNode;

typedef struct
{
    int count;
    bool full;
    ListNode *head;
}List;

void CreateList(List *l)
{
    l->count = 0;
    l->head = NULL;
    l->full = false;
}

bool isListEmpty(const List *l)
{
    return (l->head == NULL);
}

bool isListFull(const List *l)
{
    return (l->full);
}

int ListSize(const List *l)
{
    return (l->count);
}

ListNode* MakeListNode(ListEntry coeff,ListEntry expo)
{
    ListNode *p = (ListNode*) malloc(sizeof(ListNode));
    if (p)
    {
        p->coeff = coeff;
        p->expo = expo;
        p->next = NULL;
    }

    return (p);
}

void SetPosition(Position p, List *l, ListNode **current)
{
    int count;	//used through positions
    ListNode * q;	//used to travel list
    if (p < 0 || p >= l->count)
        printf("Attempt to set a position not in the list");
    else
    {
    	//count from head of list to position p
        q = l->head;
        for (count = 1; count <= p; count++)
            q = q->next;
        *current = q;
    }
}

void InsertList(Position p, ListEntry coeff,ListEntry expo, List *l)
{
    ListNode *newnode, *current;
    if (p < 0 || p > ListSize(l))
        printf("attempt to insert a position not in the list");
    else
    {
        newnode = MakeListNode(coeff,expo);
        if (newnode == NULL)
        {
            l->full = false;
            printf("Not enough memory for additional node");
        }
        else
        {
            if (p == 0)
            {
                newnode->next = l->head;
                l->head = newnode;
            }
            else
            {
                SetPosition(p - 1, l, &current);
                newnode->next = current->next;
                current->next = newnode;
            }

            l->count++;
        }
    }
}

void PrintEachTerm(const List *l){
    ListNode *current = l->head;
    printf("List:\t");
    while (current != NULL)
    {
        printf("%d(x)^%d ",current->coeff,current->expo);
        current = current->next;
    }
    
}

void TraverselList(const List *l, void(*Visit)(ListEntry,ListEntry,bool))
{
    bool firstTime = true;
    ListNode *current = l->head;
    while (current != NULL)
    {
        (*Visit)(current->coeff,current->expo,firstTime);
        firstTime = false;
        current = current->next;
    }
}

void InsertPoly(ListEntry coeff, ListEntry expo, List *l)
{
    ListNode * current;

    if (isListFull(l))
    {
        printf("List is already full");
        return;
    }
    else
    {
        if (isListEmpty(l))
        {
            InsertList(0, coeff, expo, l);
        }
        else
        {
            current = l->head;
            int pos = 0;
            while (current != NULL)
            {
                if (current->expo < expo)
                {
                    InsertList(pos, coeff, expo, l);
                    return;
                }
                else
                {
                    current = current->next;
                    pos++;
                }
            }
            InsertList(pos, coeff, expo, l);
        }
    }
}