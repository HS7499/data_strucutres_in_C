#include<stdio.h>
#include<stdlib.h>

struct node {
    int data;
    struct node* link;

};
struct node* head; //if we r not going to modify use it as global variable 

//then we need to get it in the argumen of both void function 
//it will be different for both the arguments 
// collect head again from the insert function


void insert(int x);
void print();

int main(){
    head=NULL;

    printf("enter length of list; ");
    int n,i,x;
    scanf("%d",&n);
    for (i=0;i<n;i++){
        scanf("%d",&x);
        insert(x); // also insert(&head,x)
        print(); //print(head)
        
    }   
} 

void insert(int x){ //(Node** pointertohead,int x)
    struct node* temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=x;
    (*temp).link=head;
    head=temp;
}

// void insert(int x){ //(Node** pointertohead,int x)(from end)
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     (*temp).data=x;
//     (*temp).link=NULL;
//     if (head==NULL){

//         head->link=temp;
//         head=temp;}
//     else {
//         struct node*temp2=head;
//         while (temp2->link!=NULL){
//             temp2->link=temp2;
//         }temp->link=temp2->link;
//         temp2->link=temp;


//     }
// }

void print(){

    struct node* temp=head;
    printf("list ;");
    while(temp !=NULL)
    {
        printf("%d ",(*temp).data  );
        temp=(*temp).link;
    }
    printf("\n");


}
//inserting at nth position

// void end_insert(int x){
//     struct node* temp=(struct node*)malloc(sizeof(struct node));
//     (*temp).data=x;
//     while (temp!=NULL){

//         temp=(*temp).link;

//     }
//     (*temp).link=


