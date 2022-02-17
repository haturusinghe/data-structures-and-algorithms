#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "list.h"

void storePoly(List *l)
{
    bool end = false;
    int coefficent, exponent;
    char prompt;
    do {
        printf("\tEnter coefficent: ");
        scanf("%d", &coefficent);
        printf("\tEnter exponent: ");
        scanf("%d", &exponent);
        InsertPoly(coefficent, exponent, l);

        do
        {
            printf("Continue adding more terms? (Y/N): ");
            scanf(" %c", &prompt);
        } while (prompt != 'Y' && prompt != 'N');

        if (prompt == 'N')
        {
            end = true;
        }

    } while (!end);
}

List* polyResult(List *list1, List *list2)
{
    List *resultant = (List*) malloc(sizeof(List));
    CreateList(resultant);
    ListNode *p, *q;
    p = list1->head;
    q = list2->head;

    while (p != NULL || q != NULL)
    {
        if (p != NULL && q != NULL)
        {
            if (p->expo == q->expo)
            {
                InsertPoly(p->coeff + q->coeff, p->expo, resultant);
                p = p->next;
                q = q->next;
            }
            else if (p->expo > q->expo)
            {
                InsertPoly(p->coeff, p->expo, resultant);
                p = p->next;
            }
            else if (p->expo < q->expo)
            {
                InsertPoly(q->coeff, q->expo, resultant);
                q = q->next;
            }
        }
        else if (q == NULL)
        {
            InsertPoly(p->coeff, p->expo, resultant);
            p = p->next;

        }
        else if (p == NULL)
        {
            InsertPoly(q->coeff, q->expo, resultant);
            q = q->next;

        }
    }

    return (resultant);
}

void PrintPoly(ListEntry coeff,ListEntry expo,bool firstTime)
{
    if(firstTime){
        printf("%d(x)^%d ",coeff,expo);
        firstTime = false;
    }else{
        printf("+ %d(x)^%d ",coeff,expo);
    }
}

int main(void){

    List poly1,poly2;
    CreateList(&poly1);
    CreateList(&poly2);
	printf("Frist input the coefficent of the term and press ENTER\nThen input the exponent of that term and press ENTER\nNext when the program asks Continue adding more terms?, input Y to countinue or N to stop adding terms , then press ENTER\n"); //Forgot to include this instruction in the originally uploaded version of this file
    printf("\nPolynomial 1:\n");
    storePoly(&poly1);
    printf("\nPolynomial 2:\n");
    storePoly(&poly2);
    
    printf("\n You entered the following 2 polynomials: \n");
    printf("\tPolynomial 1: ");
    TraverselList(&poly1,PrintPoly);
    printf("\n\tPolynomial 2: ");
    TraverselList(&poly2,PrintPoly);

    List* ployR =  polyResult(&poly1,&poly2);
    printf("\n\tResult of adding Polynomial 1 and Polynomial 2: ");
    TraverselList(ployR,PrintPoly);
}