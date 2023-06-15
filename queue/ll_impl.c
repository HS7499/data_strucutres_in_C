#include<stdlib.h>
#include<stdio.h>
struct node{
    int data;
    struct node* link;

};


struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int x){
    struct node* temp =(struct node*)malloc(sizeof(struct node));
    (*temp).data = x;
    (*temp).link =NULL;
    if (front== NULL && rear == NULL){
        front = rear = temp;
        return ;
    }
    (*rear).link = temp;
    rear =temp;
}

void dequeue(){
    struct node* temp = front;
    if(front == NULL){return;}
    if(front == rear ){ front = rear = NULL;
    } else {
        front =(*front).link;
    }
    free(temp);
}

void print(){
    struct node* temp = front;
    while(temp != NULL){
        printf("%d ",(*temp).data);

        temp =(*temp).link; 
    }
    printf("\n");
    return;
}

int main(){
    enqueue(2);
    enqueue(4);
    enqueue(5);
    enqueue(6);
    
    print();
    dequeue();
    dequeue();
    print();
}