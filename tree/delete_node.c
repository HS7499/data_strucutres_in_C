#include<stdio.h>
#include<stdlib.h>

struct node{

    int data;
    struct node*left;
    struct ndoe*right;

};

struct node*newnode(int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;
}
