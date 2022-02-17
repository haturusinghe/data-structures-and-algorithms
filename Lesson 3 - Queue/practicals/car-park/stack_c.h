#define MAXSTACK 10

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef Car StackEntry;

typedef struct {
    int top;
    StackEntry entry[MAXSTACK];
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

void Push(Stack* s,StackEntry e){
    if(!isStackFull(s)){
        s->entry[++s->top] = e;
    }else{
        exit(1);
    }
}

StackEntry Pop(Stack* s){
    if(!isStackEmpty(s)){
        return s->entry[s->top--];
    }else{
        exit(1);
    }
}

void PrintStack(Stack* s){
    int pt = s->top;
    while(pt >= 0){
        printf("Car :%s ",s->entry[pt--].name);
    }
    printf("\n");
}