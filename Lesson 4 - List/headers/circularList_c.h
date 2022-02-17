#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int ListEntry;

typedef int Position;

typedef struct node{
    ListEntry value;
    struct node* next;
}Node;

typedef struct {
    int count;
    bool full;
    Node* tail;
}List;

void createList(List* l){
    l->count=0;
    l->full = false;
    l->tail = NULL;
}

bool isListEmpty(List* l){
    return (l->count == 0);
}

bool isListFull(List* l){
    return (l->full);
}

Node* createNode(ListEntry e){
    Node* temp = (Node*)malloc(sizeof(Node));
    if(temp){
        temp->value = e;
        temp->next = NULL;
        return temp;
    }else{
        return NULL;
    }
}
int listSize(List* l){
    return l->count;
}

void insertList(List* l,ListEntry e,Position p){
    if(!isListFull(l)){
        Node* new_node = createNode(e);
        if(new_node){
            if(isListEmpty(l)){
                
            }else{

            }
        }else{
            l->full = true;
        }
    }else{
        exit(1);
    }
}