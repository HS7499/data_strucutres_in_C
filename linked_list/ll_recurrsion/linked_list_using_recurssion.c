#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;

};

struct node* insert(struct node* head,int data){
    struct node* temp= (struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).link=NULL;
    if (head == NULL){ head=temp;} 
    else {
        struct node* temp1= head;
        while((*temp1).link != NULL){
            temp1=(*temp1).link;}
            (*temp1).link= temp;
    }
    return head;
    }; 


void print(struct node*p){

    if (p==NULL){ return ;}
    printf("%d ",(*p).data);
    print((*p).link);
    printf("\n");

}

void Rprint(struct node*p){
    if(p == NULL){ return;}
    Rprint((*p).link);
    printf("%d ",(*p).data);
}


int main(){
    struct node*head =NULL;
    head= insert(head,2);
    head= insert(head,4);
    head=insert(head,7);
    head=insert(head,9);
    print(head);
    Rprint(head);

}