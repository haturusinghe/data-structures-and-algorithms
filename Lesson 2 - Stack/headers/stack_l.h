#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef int stackEntry;

typedef struct node{
    stackEntry value;
    struct node* next; 
}Node;

typedef struct {
    int count;
    bool full;
    Node* top;
}Stack;

void createStack(Stack *s){
    s->count = 0;
    s->full = false;
    s->top = NULL;
}

bool isStackEmpty(Stack* s){
    return (s->top == NULL);
}

bool isStackFull(Stack* s){
    return s->full;
}

Node* createNode(stackEntry e){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node){
        new_node->value = e;
        new_node->next = NULL;
        return new_node;
    }else{
        return NULL;
    }
}

void Push(Stack* s,stackEntry e){
    Node* temp = createNode(e);
    if(!isStackFull(s)){
        if(temp){
            temp->next = s->top;
            s->top = temp;
            s->count++;
        }else{
            s->full = true;
        }
    }
    

}

stackEntry Pop(Stack* s){
    Node* np;
    stackEntry e;

    if(!isStackEmpty(s)){
        e = s->top->value;
        np = s->top;
        s->top = s->top->next;
        s->count--;

        free(np);
        return e;
    }else{
        exit(1);
    }

    
}

void DestroyStack(Stack* s){
    free(s);
}

void PrintStack(Stack* s){
    Node* current;
    current = s->top;
    while(current != NULL){
        printf("%d ",current->value);
        current = current->next;
    }
    printf("\n");
}