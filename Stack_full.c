#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*next;
    struct node*prev;
};

struct stack{
    struct node*first;
    struct node*last;
};

struct stack *stackinit(){
    struct stack*tempstack;
    tempstack=malloc(sizeof(struct stack));
    tempstack->first=NULL;
    tempstack->last=NULL;
    return tempstack;
    
}

int isempty(struct stack*tempstack){
    return !tempstack->first;
}

void pushfront(struct stack*tempstack,int data){
    struct node*temp1=malloc(sizeof(struct node));
    temp1->data=data;
    temp1->next=tempstack->first;
    temp1->prev=NULL;
    if (isempty(tempstack)){
        tempstack->last=temp1;
    }else{
        tempstack->first->prev=temp1;
       
    }
    tempstack->first=temp1;   
}

int popFront(struct stack *tempstack) {
  struct node *temp;
  int data;
  if (isempty(tempstack)){
    return -1;}
  temp = tempstack->first;
  tempstack->first = temp->next;
  if (!tempstack->first)
    tempstack->last = NULL;
  else
    tempstack->first->prev = NULL;
  data = temp->data;
  free(temp);
  return data;
}

int peekFront(struct stack *tempstack) {
  if (isempty(tempstack))
    return -1;
  return tempstack->first->data;
}

//below are stack operations form downside

int peekBack(struct stack *tempstack) {
  if (isempty(tempstack)){
    return -1;}
  return tempstack->last->data;
}

void pushBack(struct stack *cardstack, int data) {
  struct node * node= malloc(sizeof(struct node));
  node->data = data;
  node->prev = cardstack->last;
  node->next = NULL;
  if (isempty(cardstack))
    cardstack->first = node;
  else
    cardstack->last->next = node;
  cardstack->last = node;
}

int popBack(struct stack *cardstack) {
  struct node *node;
  int data;
  if (isempty(cardstack))
    return -1;
  node = cardstack->last;
  cardstack->last = node->prev;
  if (!cardstack->last)
    cardstack->first = NULL;
  else
    cardstack->last->next = NULL;
  data = node->data;
  free(node);
  return data;
}

void *fronttoback(struct stack *cardstack) {
  if (isempty(cardstack))
    return NULL;
  struct node *currpointer = cardstack->last;
  while (currpointer) {
    printf("%d\n", currpointer->data);
    currpointer = currpointer->prev;
  }
}



int main(){
    struct stack*ns=stackinit();
    pushfront(ns,1);
    pushfront(ns,2);
    int m = peekFront(ns);
    pushfront(ns,3);
    popFront(ns);
    int n = peekFront(ns);
    pushfront(ns,4);
    int o = peekFront(ns);

    printf("%d %d %d",m,n,o);
    fronttoback(ns);
    }