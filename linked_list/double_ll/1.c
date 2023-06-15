#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node*prev;
    struct node*next;
};
struct node* head; //pointer to head node

struct node* gettemp(int x){
    struct node*gettemp=(struct node*)malloc(sizeof(struct node));
    (*gettemp).data=x;
    (*gettemp).prev=NULL;
    (*gettemp).next=NULL;
    return gettemp;
};

void insertathead(int x){

    struct node* temp=gettemp(x);
    if(head == NULL){
        head=temp;
        return;
    }
    (*head).prev=temp;
    (*temp).next=head;
    head=temp;
}

void print(){
    struct node*temp=head;
    while(temp!= NULL){
        printf("%d ",(*temp).data);
        temp=(*temp).next;
    }
    printf("\n");
}

void reverseprint(){
    struct node*temp =head;
    if (temp == NULL){return;}
    while((*temp).next != NULL){
        temp = (*temp).next;
    }

    while(temp !=NULL){
        printf("%d ",(*temp).data);
        temp =(*temp).prev;
    }
    printf("/n");
    
}

int main(){

    head = NULL;
    insertathead(2); print(); 
    insertathead(4); print();
    insertathead(6);print(); reverseprint();



}