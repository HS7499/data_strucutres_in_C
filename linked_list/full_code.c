#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct node
{
int data;
struct node *next;
};

struct node *create_ll(struct node *start)
{
struct node *new_node, *ptr;
int num;
printf("Enter the data : \n");
scanf("%d", &num);
while(num!=-1)
{
		
new_node = (struct node*)malloc(sizeof(struct node));
		
new_node -> data=num;
		if(start==NULL)
		{
			
new_node -> next = NULL;
			start = new_node;
		}
		else
		{
			ptr=start;
            while(ptr->next!=NULL)
			ptr=ptr->next;
			ptr->next = new_node;
			new_node->next=NULL;
		}
		
		scanf("%d", &num);
}
return start;
}