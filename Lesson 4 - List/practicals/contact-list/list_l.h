//LINKED LIST HEADER
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

typedef struct {
    char name[20];
    char number[11];
}Contact;

typedef Contact ListEntry;

typedef int Position;

typedef struct node{
    ListEntry value;
    struct node* next;
}Node;

typedef struct {
    int count;
    bool full;
    Node* head;
}List;

void updateCount(List* l){
    Node* current = l->head;
    int n = 0;
    while (current)
    {
        n++;
        current = current->next;
    }
    l->count = n;
    
}

void createList(List* l){
    l->count=0;
    l->full = false;
    l->head = NULL;
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
    updateCount(l);
    return l->count;
}

void setPosition(List* l,Position p, Node **current){
    Node* q;

    if(p < 0 || p >= listSize(l)){
        printf("Error Position\n");
        exit(1);
    }else{
        q = l->head;
        for(int i = 1; i <= p; i++){
            q = q->next;
        }
        *current = q;
    }
}

void insertList(List * l, ListEntry e, Position p) {
  if (!isListFull(l)) {
    if (p < 0 || p > listSize(l)) {
        printf("Error Position\n");
      exit(1);
    } else {
      Node * new_node = createNode(e);
      if (new_node != NULL) {
        if (p == 0) {
          new_node -> next = l -> head;
          l -> head = new_node;
        } else {
          Node * np = NULL;
          setPosition(l, p-1, & np);
          new_node -> next = np -> next;
          np -> next = new_node;
        }

        l -> count++;
      } else {
        l -> full = true;
        return;
      }

    }
  }
}

void insertLast(List* l, ListEntry e){
    if(!isListFull(l)){
        if(listSize(l) > 0){
                insertList(l,e,listSize(l));
            }else{
                insertList(l,e,0);
            }
    }else{
        printf("Error Inserting\n");
        exit(1);
    }
}

ListEntry removeList(List* l,Position p){
    if(!isListEmpty(l)){
        Node *np,*temp;
        ListEntry value;
        setPosition(l,p-1,&np);
        temp = np->next;
        value = np->next->value;
        np->next = np->next->next;
        free(temp);
        return value;
    }else{
        printf("Error Removing\n");
        exit(1);
    }
}


ListEntry removeLast(List* l){
    removeList(l,listSize(l)-1);
}

void removeContact(List* l, ListEntry e){
    Node* current;
    current = l->head;
    int pos = -1;
    int i = 0;
    while(current != NULL){
        if(strcmp(current->value.name,e.name) == 0){
            pos = i;
            printf("Position: %d",pos);
            break;
        }
        current = current->next;
        i++;
    }
    if(pos != -1){
        removeList(l,pos);
    }else{
        printf("Not Found\n");
    }
}


void printList(List* l){
    Node* current;
    current = l->head;
    while(current != NULL){
        printf("%s %s \n",current->value.name,current->value.number);
        current = current->next;
    }
    printf("\n");
}