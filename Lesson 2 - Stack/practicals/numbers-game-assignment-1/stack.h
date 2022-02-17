//Student Number CS/2018/015
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define MAXSTACK 50
typedef int StackEntry;

typedef struct 
    {
        int top;
        StackEntry entry[MAXSTACK];
    }Stack;

void CreateStack(Stack *s){
    s->top=-1;
}

bool isStackFull(const Stack *s){
    return (s->top == MAXSTACK-1);
}

bool isStackEmpty(const Stack *s){
    return (s->top == -1);
}

void Push(StackEntry item,Stack *s){
if(!isStackFull(s)){
        s->entry[++s->top] = item;
    }
    else{
        printf("\nError: Stack is Full\n");
        exit(1);
    }
}

void Pop(StackEntry *item,Stack *s){
    if(!isStackEmpty(s)){
        *item = s->entry[s->top--];
    }
    else{
        printf("\nError: Stack is Empty\n");
        exit(1);
    }
}