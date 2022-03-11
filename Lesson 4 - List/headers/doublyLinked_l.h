#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

typedef int ListEntry;
typedef int Position;

typedef struct node{
    ListEntry e;
    struct node* next;
    struct node* prev;
}Node;

typedef struct list{
    int count;
    bool full;
    Node* current;
    Position currentPosition;
}List;


void createList(List* l){
    l->count = 0;
    l->full = false;
    l->current = NULL;
    l->currentPosition = -1;
}

bool isListEmpty(List* l){
    return l->count == 0;
}

bool isListFull(List* l){
    return l->full;
}

Node* makeNewNode(ListEntry e){
    Node* new_node = (Node*)malloc(sizeof(Node));
    if(new_node){
        new_node->e = e;
        new_node->next = NULL;
        new_node->prev = NULL;
        return new_node;
    }else{
        return NULL;
    }
}

int getListCount(List* l){
    return l->count;
}

Node* setPosition(Position p, List* l){
    if(!isListEmpty(l)){
        if(p > l->currentPosition){
            while(p != l->currentPosition){
                l->current = l->current->next;
                l->currentPosition++;
            }
        }else if(p < l->currentPosition){
            while(p != l->currentPosition){
                l->current = l->current->prev;
                l->currentPosition--;
            }
        }
    }
}

void InsertList(ListEntry e, Position p, List* l){
    setPosition(p-1, l);
    Node* temp = makeNewNode(e);
    if(temp){
        temp->next = l->current->next;
        temp->prev = l->current;
        l->current->next = temp;
    }else{
        l->full = true;
    }

}

