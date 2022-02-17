// CIRCULAR QUEUE HEADER FILE
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 20
typedef int queueEntry;

typedef struct queue {
    int top;
    int rear;
    int count;
    queueEntry entries[MAX];
}Queue;

void CreateQueue(Queue* q){
    q->rear = -1;
    q->top = 0;
    q->count =0;
}

bool isQueueFull(Queue* q){
    return (q->top == MAX - 1);
}

bool isQueueEmpty(Queue *q){
    return (q->rear < q->top);
}

void Append(Queue* q, queueEntry e){
    if(!isQueueFull(q)){
        q->rear = (q->rear + 1) % MAX;
        q->entries[q->rear] = e;
        q->count++;
    }else{
        exit(1);
    }
}

queueEntry Serve(Queue* q){
    if(!isQueueEmpty(q)){
        int e;
        q->count--;
        e =  q->entries[q->top];
        q->top = (q->top + 1) % MAX;
        return e;
    }else{
        exit(1);
    }
}

void PrintQueue(Queue* q){
    if(!isQueueEmpty(q)){
        int pt = q->top;
        while(pt <= q->rear){
            printf("%d ",q->entries[pt++]);
        }
        printf("\n");
    }
}