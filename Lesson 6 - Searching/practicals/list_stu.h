#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20

typedef struct student{
    int stuId;
    int age;
    char* name;
}Student;

typedef Student ListEntry;

typedef int Position;

typedef struct {
    int count;
    Student students[MAX];
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
        l->students[l->count++] = e;
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
                l->students[pt+1] = l->students[pt];
            }
            l->students[p] = e;
            l->count++;
        }
    }
}

ListEntry deleteList(List* l,Position p){
    if(!isListEmpty(l)){
        if(0 > p || p > listSize(l)){
            exit(1);
        }else{
            ListEntry e = l->students[p];
            for(int i = p; i < listSize(l); i++){
                l->students[i] = l->students[i+1];
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
            return l->students[p];
        }
    }
}

void replaceList(List* l,Position p,ListEntry e){
    if(!isListEmpty(l)){
        if(0 > p || p > listSize(l)){
            exit(1);
        }else{
            l->students[p] = e;
        }
    }
}

void printList(List* l){
    for(int i = 0; i < listSize(l); i++){
        printf("ID: %d ",l->students[i].stuId);
    }
    printf("\n");
}