#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* left;
    struct node* right;
};

struct node*root= NULL;


struct node* newnode(int data){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    (*temp).data= data;
    (*temp).left = NULL;
    (*temp).right=NULL;
    return temp;
}

struct node* insert(struct node* root,int data){
    if(root == NULL){
       root = newnode(data);
        return root;
    } else if (data<=(*root).data){
        (*root).left=insert((*root).left,data);
    }else {
        (*root).right=insert((*root).right,data);
    }
    return root;
}

void inorder(struct node* root)
{
    if (root != NULL) {
    inorder(root->left);
    printf("%d \n", (*root).data);
    inorder(root->right);
    }
}

// struct node* search(struct node* root,int data){
//     if (root == NULL){
//         return 0;
//     }
//     else if ((*root).data==data){
//         return 1;
//     }
//     else if ((data<= (*root).data)){
//         return search((*root).left,data);
//     }
//     else{
//         return search((*root).right,data);
//     }
// }

// int search(struct node*root,int data){
//     while(temp!=NULL){
//         if(data=(*temp).data){
//             return 1;
//         }
//         else if(data<= (*temp).data){
//             temp=(*temp).left;
//         }
//         else{
//             temp=(*temp).right;
//         }
//     }
//     return 0;
// }   

// C function to search a given key in a given BST
struct node* search(struct node* root, int data)
{
	// Base Cases: root is null or key is present at root
	if (root == NULL || root->data == data)
	return root;
	
	// Key is greater than root's key
	if (root->data < data)
	return search(root->right, data);

	// Key is smaller than root's key
	return search(root->left, data);
}


int main(){

    struct node*root=NULL;
    root =insert(root,15);
    root = insert(root,10);
    root = insert(root,20);
    root = insert(root,25);
    root = insert(root,8);
    root = insert(root,12);

    inorder(root);
    int found =search(root,10);
    if (found) {
        printf("found");
    }else {
        printf("not found");
    }
}

