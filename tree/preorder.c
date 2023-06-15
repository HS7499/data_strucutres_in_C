#include<stdio.h>
#include<stdlib.h>

struct node{
    int data ;
    struct node*left;
    struct node* right;
};

struct node* root=NULL;

struct node*newnode(int data){
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;

}

struct node*insert(struct node*root,int data){
    if (root == NULL){
        root=newnode(data);
        return root;
    } else if(data <= (*root).data){
        (*root).left=insert((*root).left,data);

    }else {
        (*root).right=insert((*root).right,data);
    }
    return root;
}
void preorder(struct node* root){
    if (root!=NULL){
        printf("%d \n",(*root).data);
        preorder((*root).left);
        preorder((*root).right);
    }

}

void postorder(struct node* root){
    if (root != NULL){
        postorder((*root).left);
        postorder((*root).right);
        printf("%d \n",(*root).data);
    }
}
/*
                15
        10             20
    8       12              25


*/

int main(){
    root= insert(root,15);
    root = insert(root,10);
    root=insert(root,20);
    root=insert(root,25);
    root=insert(root,8);
    root=insert(root,12);

    
    preorder(root);
    postorder(root);
}