//Student Number CS/2018/015
#include "stack.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void generateNumbersSet(int count,int upper,int lower,int numbers[]){
    srand(time(0));

    for (int i = 0; i < count; i++) {
        int tempNum = (rand() % (upper - lower + 1)) + lower;
        numbers[i] = tempNum;
    }
}

void populateStack(Stack *S,int numbersContainer[],int count,bool isReversed){
    if(!isReversed)
    {
        for (int i = 0; i < count; i++) {
            Push(numbersContainer[i],S);
        }
    }else{
        for (int i = count-1 ; i >= 0; i--) {
            Push(numbersContainer[i],S);
        }
    }
}

void makeMove(Stack *A,Stack *B){
    int moveA = 0;
    int moveB = 0;

    Pop(&moveA,A);
    Pop(&moveB,B);
    
    if (moveA > moveB){
        printf("2 ");
        Push(moveB,B);
    }else if (moveB > moveA){
        printf("1 ");
        Push(moveA,A);
    }else if(moveA == moveB){
        printf("0 ");
    }
}


int main(void){
    Stack boxA,boxB;
    int count = -1;
    int numbersContainer[20];
    int x = 15; //Student Number is CS/2018/015 thus upperlimit(inclusive) = 15
    int lower = 0;
    bool gameOver = false;
    CreateStack(&boxA);
    CreateStack(&boxB);

    do{
        printf("Input: ");
        scanf("%d",&count);
    }while(count < 5 || count > 20);
    
    generateNumbersSet(count,x,lower,numbersContainer);
    printf("Output: \n\t");
    populateStack(&boxA,numbersContainer,count,false);
    populateStack(&boxB,numbersContainer,count,true);

    while(!gameOver)
    {
        makeMove(&boxA,&boxB);

        if(isStackEmpty(&boxA)){
            printf("\n\tA is the Winner");
            gameOver = true;
        }if(isStackEmpty(&boxB)){
            printf("\n\tB is the Winner");
            gameOver = true;
        }
    }
    return 0;
}
