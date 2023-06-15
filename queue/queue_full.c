#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;

};

struct queue{
    struct node*front;
    struct node*rear;
};

typedef struct queue queue;

void intialize(queue*q){
    q->front=NULL;
    q->rear=NULL;
}

int isempty(queue *q){
    return q->front==NULL;
}

void push(queue*q,int value){
    struct node*newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=NULL;
    if (isempty(q)){
    newnode->next=q->rear=q->front;
    }else {
    q->rear->next=newnode;
    q->rear=newnode;    
    }
}

int pop(queue*q){
    if (isempty(q)){
        printf("underflow");
        return -1;
    }else {
        struct node*topnode=q->front;
        int value =topnode->data;
        q->front =topnode->next;
        free(topnode);
        return value;
    }
}