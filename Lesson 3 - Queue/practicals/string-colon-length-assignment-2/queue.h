//CT_2018_015
//Question 01
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef char QueueElement;


typedef struct node {
    QueueElement entry;
    struct node *next;
}Node;

typedef struct {
    Node *front;
    Node *rear;
    int count;
    bool full;
}Queue;

void CreateQueue(Queue *q)
{
    q->count = 0;
    q->full = false;
    q->front = q->rear = NULL;
}

bool isQueueEmpty(Queue *q){
    if (q->front == NULL && q->rear == NULL){
        return true;
    }else {
        return false;
    }
}

bool isQueueFull(Queue *q){
    return (q->full);
}

void Append(Queue *q,QueueElement x){
    Node *np;
    np=(Node *)malloc(sizeof(Node));
    if(np==NULL){
        printf("Not enough memory");
        q->full=true;
    }else{
        np->entry=x;
        np->next=NULL;
        if(isQueueEmpty(q)){
            q->front=q->rear=np;
        }else{
            q->rear->next=np;
            }
        q->count++;
        // printf("%c",x);
    }
}


void Serve(QueueElement * x, Queue * q) {
    Node *np;
    if (isQueueEmpty(q)) {
        printf("Queue is empty");
        exit(1);
    } else {
        *x = q ->front->entry;
        np = q->front;
        q->front = q->front->next;
        q->count--;
        if (q->front == NULL)
            {q-> rear = NULL;}
        free(np);
    }
}

