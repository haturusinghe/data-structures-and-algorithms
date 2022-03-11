#define MAXSTACK 20

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void errorMsg(char* msg){
    printf("Error! : %s\n", msg);
}

void successMsg(char* msg){
    printf("Success! : %s\n", msg);
}

typedef int stackEntry;

typedef struct {
    int top;
    stackEntry entry[MAXSTACK];
}Stack;

void createStack(Stack* s){
    s->top = -1;
}

bool isStackFull(const Stack* s){
    return s->top == MAXSTACK - 1;
}

bool isStackEmpty(const Stack* s){
    return s->top == -1;
}

void Push(Stack* s,stackEntry e){
    if(!isStackFull(s)){
        s->entry[++s->top] = e;
    }else{
        errorMsg("Couldnt push item to stack");
    }
}

stackEntry Pop(Stack* s){
    if(!isStackEmpty(s)){
        return s->entry[s->top--];
    }else{
        errorMsg("Couldnt pop item from stack");
    }
}

void PrintStack(Stack* s){
    int pt = s->top;
    while(pt >= 0){
        printf("%d ",s->entry[pt--]);
    }
    printf("\n");
}