#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node* left;
    struct node*right;
};

struct node*root = NULL;

struct node*newnode(int data){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;
};

struct node*insert(struct node* root,int data){
    if (root == NULL){
    struct node*temp = newnode(root);
    return root;
    }else if(data<= (*root).data){
        (*root).left=insert((*root).right,data);
    }else {
        (*root).right=insert((*root).right,data);
    }
    return root;
};

//creating queue 

struct box{
    int data;
    struct box*link;
};

struct box*front=NULL;
struct box*rear= NULL;

void enqueue(int data){
    struct box*temp=(struct box*)sizeof(struct box);
    (*temp).data= data;
    (*temp).link=NULL;
    if (front==NULL && rear==NULL){
        front=rear=temp;
        return ;
    }
    (*rear).link=temp;
    (rear)=temp;
}
// for level order transversal 
void levelorder(struct box*){


}

