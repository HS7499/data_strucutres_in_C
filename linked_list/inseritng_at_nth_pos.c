#include<stdio.h>
#include<stdlib.h>


struct node{
    int data;
    struct node* link;
};
struct node* head;

void print(){
    struct node*temp =head;
    while(temp != NULL){
        printf("%d ",(*temp).data);
        temp=(*temp).link;
    }
    printf("\n");
    return;
}


void insert(int data,int n){
    struct node* temp1=(struct node*)malloc(sizeof(struct node));
    (*temp1).data=data;
    (*temp1).link=NULL;
    if (n==1){
        (*temp1).link=head;
        head=temp1;
        return;
    }
    struct node* temp2 = head;
    for (int i=0;i<n-2;i++){
        temp2=(*temp2).link;
    }
    (*temp1).link=(*temp2).link;
    (*temp2).link=temp1;
    
    };


int main(){
    head =NULL;//empty list
    insert(2,1);
    insert(3,2);
    insert(4,1);
    insert(5,2);
    print();
    
    

}