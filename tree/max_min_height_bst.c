#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* left;
    struct node* right ;
};

struct node* root = NULL;

struct node* newnode(int data){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).left = NULL;
    (*temp).right= NULL;
    return temp;
}

struct node* insert(struct node*root,int data){
    if (root==NULL){
        root =newnode(data);
    }else if (data <= (*root).data){
        (*root).left=insert((*root).left,data);
    }else {
        (*root).right=insert((*root).right,data);
    }
    return root;
}

void inorder(struct node*root){
    if (root != NULL){
        inorder((*root).left);
        printf("%d ",(*root).data);
        inorder((*root).right);
    }
}
//loop approach for finding the min 
//similar for right gives min
int min(struct node*root){
    struct node*current= root;
    if (root == NULL){
        printf("empty");
        return -1;
    }
    while((*current).left!=NULL){
        current=(*current).left;
    }
    return (*current).data;
    printf("\n");
}
//is only for amx funtion
// void maximum(int a,int b){
//     if(a>b){
//         return a;
//     }else {return b;}
// }
//////

//below is recurssive approach to find max 
// similar is for left to find min
int max(struct node*root){
    if(root == NULL){
        printf("empty");
        return -1;
    } else if ((*root).right ==NULL){
        return (*root).data;
    }
    return max((*root).right);
}

int height(struct node*root){
    if(root== NULL){
        return -1;
    }
    return max(height((*root).left),height((*root).right)) +1 ;
}

int main(){

    struct node*root=NULL;
    root =insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);
    // inorder(root);
    printf("%d ",min(root));
    printf("%d ",max(root));
    printf("%d ",height(root));
}


//in height function max is not working 


