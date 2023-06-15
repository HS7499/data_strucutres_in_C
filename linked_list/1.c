#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* link;
};
struct node*A;
int main(){
A =NULL;
struct node* temp=(struct node*)malloc(sizeof(struct node)); // pointer to node 
(*temp).data=2;
(*temp).link=NULL;
A=temp;

}