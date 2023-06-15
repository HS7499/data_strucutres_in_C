#include<stdio.h>
#include<stdlib.h>



int A[10];
int front =-1;
int rear = -1;

void isempty(){
    if (front == -1 && rear == -1){
        return 1;
    } else {
        return 0; }
}


void enqueue(int x){
    if (front == 10 -1){
        printf("queue is full");
        return;
    } else if (isempty == 1)
    {  front==rear==0;}
    else { rear =rear+1;}
    A[rear]=x;
}

void dequeue(int x){
    if (isempty == 1){ return;    }
    else if (front==rear)
    {front==rear==-1 ;}
    else{front = front+1;}
}

void print(){
    
    for (int i = front;i<rear;i++){
        printf("%d ",A[i]);
    }
    printf("\n");
}

int main(){

    enqueue(2); print();
    enqueue(4); print();
    enqueue(6); print();
    dequeue(2); print();
}