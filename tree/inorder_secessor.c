#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node* root = NULL;

struct node*newnode(int data){
    
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).left=NULL;
    (*temp).right=NULL;
    return temp;
}

struct node*insert(struct node*root,int data){
    if(root==NULL){
        root=newnode(data);
        return root;
    } else if (data<=(*root).data){
        (*root).left=insert((*root).left,data);
    } else {
        (*root).right=insert((*root).right,data);
    }
    return root;
}

struct node* find(struct node*root,int data){
    if (root == NULL || (*root).data==data){
        return root;
    } else if (data <(*root).data){
        return find((*root).left,data);
    } else { 
        return find((*root).right,data); 
    }
}



//for inorder sucessor

struct node* getsucessor(struct node*root,int data){
    //search the node
    struct node* current =find(root,data);
    if (current ==NULL){return NULL;}
    //case 1 : root has right subtree
    if ((*current).right != NULL){
        struct node*temp =(*current).right;
        while ((*temp).left !=NULL){
            temp = (*temp).left;
            return temp;
        }
        if (temp == NULL){ return; }
        else {return temp;}
    }
    // case 2: right subtree is absent
    else {
        
    }
}



int main(){


}