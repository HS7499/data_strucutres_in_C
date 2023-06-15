#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

struct node{
    int data;
    struct node*link;
}; 
typedef struct node node;

struct queue{
    node*front;
    node*rear;

};
typedef struct queue queue;

queue*intialize(int n )
