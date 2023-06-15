#include<stdio.h>
#include<stdlib.h>

//in this we printeda list in reverse order with one pointer by adding nenode and making the newnode as the head.

struct node{
    int data;
    struct node* link;
};

struct node* head;

void insert(int x){ //(Node** pointertohead,int x)
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=x;
    (*temp).link=head;
    head=temp;
}

void print(){

    struct node* temp=head;
    while(temp !=NULL)
    {
        printf("%d ",(*temp).data  );
        temp=(*temp).link;
    }
    printf("\n");}

void delete(int n)
    
{
    struct node* temp1 =head;
    if (n==1){
        head=(*temp1).link;//head now points to second node
        free(temp1);
        return;
    }
    
    for (int i=0;i<n-2;i++){
        temp1=(*temp1).link;}//temp1 now points to n-1th node
    struct node* temp2=(*temp1).link; //nth node
    (*temp1).link=(*temp2).link;//(n+1)th node
    free(temp2);
    


};





int main(){

    head= NULL;
    insert(2);
    insert(4);
    insert(6);
    insert(5);
    print();
    int n;
    scanf("%d",&n);
    delete(n);
    print();


};