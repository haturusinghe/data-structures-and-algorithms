#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int queueEntry;

typedef struct node{
    queueEntry value;
    struct node* next;
}Node;

typedef struct{
    int count;
    Node* front;
    Node* rear;
    bool full;
}Queue;



void createQueue(Queue* q){
    q->count = 0;
    q->front = NULL;
    q->rear = NULL;
    q->full = false;
}

bool isQueueEmpty(Queue* q){
     return (q->front == NULL);
}

bool isQueueFull(Queue* q){
     return q->full;
}

Node* createNode(queueEntry e){
    Node* new_node = (Node*)malloc(sizeof(Node));

    if(new_node){
        new_node->value = e;
        new_node->next = NULL;
        return new_node;
    }else{
        return NULL;
    }
}

void Append(Queue* q, queueEntry e){
    if(!isQueueFull(q)){
        Node* tmp = createNode(e);
        if(tmp){
            if(isQueueEmpty(q)){
                q->front = q->rear = tmp;
               
            }else{
                q->rear->next = tmp;
                q->rear = tmp;
            }
            q->count++;
        }else{
            q->full = true;
        }
    }
}

int Serve(Queue* q){
    Node* np;
    int e;
    if(!isQueueEmpty(q)){
        np = q->front;
        e = q->front->value;
        q->front = q->front->next;
        q->count--;
        free(np);
        return e;
    }
}

void PrintQueue(Queue* q){
    Node* current = q->front;

    while (current != NULL)
    {
        printf("%d ",current->value);
        current = current->next;
    }
    printf("\n");
    
}