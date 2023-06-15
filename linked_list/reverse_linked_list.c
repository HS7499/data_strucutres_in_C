#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* link;
};
struct node* reverse(struct node* head){

    struct node*current,*prev,*next;
    current = head ;
    prev = NULL;
    while(current != NULL)
    {
        next =(*current).link;
        (*current).link=prev;
        prev = current;
        current = next;
    }
    head= prev;
    return head;
};


struct node* insert(struct node*head,int data){
    
    struct node * temp=(struct node*)malloc(sizeof(struct node));
    (*temp).data=data;
    (*temp).link=NULL;
    if (head == NULL){ head= temp; }
    else 
    {   struct node* temp1= head;
        while((*temp1).link !=NULL){
            temp1 =(*temp1).link;}
        
        (*temp1).link=temp; }
    return head;}



void print(struct node* head)
{
    while (head != NULL ){
        printf("%d ",(*head).data);
        head=(*head).link;
    }
    printf("\n");
}






int main(){
    struct node* head= NULL;
    head=insert(head,2);
    head=insert(head,4);
    head=insert(head,6);
    head=insert(head,8);
    print(head);
    head=reverse(head);
    print(head);

}
 