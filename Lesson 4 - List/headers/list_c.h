#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
typedef int ListEntry;

typedef int Position;

typedef struct {
    int count;
    ListEntry items[MAX];
}List;

void createList(List* l){
    l->count=0;
}

bool isListEmpty(List* l){
    return (l->count == 0);
}

bool isListFull(List* l){
    return (l->count == MAX);
}

void insertLast(List* l, ListEntry e){
    if(!isListFull(l)){
        l->items[l->count++] = e;
    }else{
        exit(1);
    }
}

int listSize(List* l){
    return l->count;
}

void insertList(List* l, ListEntry e,Position p){
    if(!isListFull(l)){
        if(0 > p || p > listSize(l)){
            exit(1);
        }else{
           
            for(int pt = listSize(l) - 1; pt >= p; pt--){
                l->items[pt+1] = l->items[pt];
            }
            l->items[p] = e;
            l->count++;
        }
    }
}

ListEntry deleteList(List* l,Position p){
    if(!isListEmpty(l)){
        if(0 > p || p > listSize(l)){
            exit(1);
        }else{
            int e = l->items[p];
            for(int i = p; i < listSize(l); i++){
                l->items[i] = l->items[i+1];
            }
            l->count--;
            return e;
        }
    }
}

ListEntry retriveList(List* l,Position p){
    if(!isListEmpty(l)){
        if(0 > p || p > listSize(l)){
            exit(1);
        }else{
            return l->items[p];
        }
    }
}

ListEntry replaceList(List* l,Position p,ListEntry e){
    if(!isListEmpty(l)){
        if(0 > p || p > listSize(l)){
            exit(1);
        }else{
            l->items[p] = e;
        }
    }
}

void printList(List* l){
    for(int i = 0; i < listSize(l); i++){
        printf("%d ",l->items[i]);
    }
    printf("\n");
}