#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX 20

typedef struct car
{
   char name[3]; // 
}Car;

typedef Car QueueEntry;



typedef struct queue {
    int top;
    int rear;
    int count;
    Car cars[MAX];
}Queue;

void CreateQueue(Queue* q){
    q->rear = -1;
    q->top = 0;
    q->count = 0;
}

bool isQueueFull(Queue* q){
    return (q->rear == MAX - 1);
}

bool isQueueEmpty(Queue *q){
    return (q->rear < q->top);
}

void Append(Queue* q, QueueEntry e){
    
    // printf("%s \n",e.name);
    if(!isQueueFull(q)){
        // strcpy(q->cars[++q->rear],e);
        q->cars[++q->rear] = e;
        q->count++;
    }else{
        printf("Error Appending %s\n",e.name);
        exit(1);
    }
}

QueueEntry Serve(Queue* q){
    if(!isQueueEmpty(q)){
        q->count--;
        Car out = q->cars[q->top++];
        return out;
    }else{
        printf("Error Serving\n");
        exit(1);
    }
}

void PrintQueue(Queue* q){
    
    if(!isQueueEmpty(q)){
        int pt = q->top;
        int i = 1;
        while(pt <= q->rear){
            printf("Car #%d : %s\n",i,q->cars[pt++].name);
            i++;
        }
        printf("\n");
    }
}

bool FindCar(Queue* q,QueueEntry e){
    bool isFound = false;
    if(!isQueueEmpty(q)){
        int pt = q->top;
        while(pt <= q->rear){
            Car temp = q->cars[pt++];
            if(strcmp(temp.name,e.name) == 0){
                printf("%s == %s Found\n",temp.name,e.name);
                isFound = true;
                break;
            }
        }
        printf("\n");
    }
    return isFound;
}