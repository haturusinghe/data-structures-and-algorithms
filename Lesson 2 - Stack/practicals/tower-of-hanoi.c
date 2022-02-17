#include "StackInt.h"
#include <stdio.h>
#include <conio.h>
#include <math.h>

void populateStack(Stack *s,int count){
    int num = count;
    for (int i = 0; i < count; i++)
    {
        Push(num--,s);
        // printf("%d",s->entry[s->top]);
    }
    
}


void moveTopItem(Stack *source,Stack *destination){
    int item;
    Pop(&item,source);
    Push(item,destination);
}

void printMove(char source,char destination){
    printf("Move top piece of %c to %c\n",source,destination);
}

void decideLegalMove(Stack *a,Stack *b,char aName,char bName){
    if(!isStackEmpty(a) && !isStackEmpty(b)){  
        if (a->entry[a->top] < b->entry[b->top]){
            moveTopItem(a,b);
            printMove(aName,bName);
        }else{
            moveTopItem(b,a);
            printMove(bName,aName);
        }
    }else if(isStackEmpty(a)){
        moveTopItem(b,a);
        printMove(bName,aName);
    }else if(isStackEmpty(b)){
        moveTopItem(a,b);
        printMove(aName,bName);
    }
}


int main(void){
    Stack A,B,C;
    int diskCount;
    CreateStack(&A);
    CreateStack(&B);
    CreateStack(&C);

    printf("Enter the Number of Disks: ");
    scanf("%d",&diskCount);
    populateStack(&A,diskCount);
    int moveCount = pow(2,diskCount) - 1;

     Stack* source = &A;
     char sourceName = 'A';

     char destinationName,auxName;
     Stack* destination = 0;
     Stack* aux = 0;

    if(moveCount % 2 == 0){
         destination = &C;
         destinationName = 'C';

         aux = &B;
         auxName = 'B';
    }else{
        destination = &B;
        destinationName = 'B';

        aux = &C;
        auxName = 'C';
    }
    
    for (int j = 1; j <= moveCount; j++){
        if(j % 3 == 1){
            decideLegalMove(source,destination,sourceName,destinationName);
        }else if(j % 3 == 2){
            decideLegalMove(source,aux,sourceName,auxName);
        }else if(j % 3 == 0){
            decideLegalMove(aux,destination,auxName,destinationName);
        }
    }

    return 0;
}
