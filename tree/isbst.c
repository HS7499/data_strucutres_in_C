#include<stdio.h>
#include<stdlib.h>


// function to check if bst is corect or not .
struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node*root=NULL;

struct node*newnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;
}

struct node* insert(struct node*root,int data){
    if (root == NULL){
        struct node*root = newnode(data);
        return root;
    } else if (data<= (*root).data){
        (*root).left= insert((*root).left,data);

    }else {
        (*root).right=insert((*root).right,data);
    }
    return root;
}

//function to know if bst or not

int isleftsub(struct node* root,int value){
    if (root== NULL){return 1; }
    if ((*root).data <= value && isleftsub((*root).left,value) && isleftsub((*root).right,value)){
        return 1 ;
    } else {
        return 0;
    }
}

int isrightsub(struct node* root,int value ){
    if(root==NULL){return 1;}
    if ((*root).data >= value && isrightsub((*root).left,value) && isrightsub((*root).left,value)){
        return 1;
    } else {
        return 0;
    }
}



int isbst(struct node*root){
    if (root== NULL){
        return 1;
    } if (isleftsub((*root).left,(*root).data) && isrightsub((*root).right,(*root).data) && isbst((*root).left) && isbst((*root).right)) {
        return 1 ;
    } else {
        return 0;
    }
}

int main(){

    root=insert(root,15);
    root=insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);

    if(isbst){
        printf("correct");
   } else {
    printf("incorrect");
   }

}