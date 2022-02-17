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
        q->entries[++q->rear] = e;
        q->count++;
    }else{
        exit(1);
    }
}

queueEntry Serve(Queue* q){
    if(!isQueueEmpty(q)){
        q->count--;
        return q->entries[q->top++];
    }else{
        exit(1);
    }
}

void Push(Queue* q, queueEntry e){
    if(isQueueFull(q)){
        exit(1);
    }else{
        if(!isQueueEmpty(q)){
            if(q->top == 0){
                for(int i = q->rear; i >= q->top; i--){
                    q->entries[i+1] = q->entries[i];
                }
                q->entries[q->top] = e;
                q->rear++;
            }else{
                q->entries[--(q->top)] = e;
                q->rear++;
            }
        }else{
            Append(q,e);
        }
        q->count++;
    }

    
}

queueEntry Pop(Queue* q){
    if(!isQueueEmpty(q)){
        q->count--;
        return q->entries[q->rear--];
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