#include<stdlib.h>
#include<stdio.h>
#define max 50

struct queue{
    int items[max];
    int front,rear;
};

void initqueue(struct queue* q){
    q->front=-1;
    q->rear=-1;
}

int isFull(struct queue* q){
    return q->rear==max-1;
}

int isEmpty(struct queue* q){
    return q->front==-1;
}

void enqueue(struct queue* q,int value){
    if(isFull(q)){
        printf("Queue is full\n");
        return;
    }
    if(q->front==-1){
        q->front=0;
    }
    q->rear++;
    q->items[q->rear]=value;
    printf("Enqueued:%d\n",value);
}

int dequeue(struct queue* q){
    if(isEmpty(q)){
        printf("Queue is empty\n");
        return -1;
    }
    int item=q->items[q->front];
    if(q->front==q->rear){
        q->front=q->rear=-1;
    }
    else{
        q->front++;
    }
    return item;
}

int main(){
    struct queue q;
    initqueue(&q);
    enqueue(&q,10);
    enqueue(&q,20);
    enqueue(&q,30);
    printf("Dequeued:%d\n",dequeue(&q));
    return 0;
}

