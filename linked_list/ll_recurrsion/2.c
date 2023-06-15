#include<stdio.h>
#include<stdlib.h>
// error maybe due to *head as global variable
struct node {
    int data;
    struct node* link;

};
struct node*head;
struct node* insert(struct node*head,int data){

    struct node*temp =(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).link=NULL;

    if (temp == NULL){ temp =head;}
    else {
        struct node* temp1 =head;
        while((*temp1).link != NULL){
            temp1 =(*temp1).link;}
            (*temp1).link = temp;
    }
    return head;

};

void reverse(struct node* p){

    if ((*p).link == NULL){
        head = p;
        return;
    } 
    reverse((*p).link);
    struct node* q = (*p).link;
    (*q).link= p;
    (*p).link=NULL;
}

void print(){
    struct node*temp =head;
    while(temp != NULL){
        printf("%d ",(*temp).data);
        temp=(*temp).link;
    }
    printf("\n");
    return;
}


int main(){

    head= insert(head,2);
    head= insert(head,4);
    head=insert(head,7);
    head=insert(head,9);
    print(head);
    reverse(head);
    print(head);
}