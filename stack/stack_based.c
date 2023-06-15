#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;

};


struct stack{
    struct node*top;
};

typedef struct stack stack;

void intialize(stack*s){
    s->top=NULL;
}

int isempty(stack *s){
    return s->top==NULL;
}

void push(stack*s,int value){
    struct node*newnode=(struct ndoe*)malloc(sizeof(struct node));
    newnode->data=value;
    newnode->next=s->top;
    s->top=newnode;
}

int pop(stack*s){
    if (isempty(s)){
        printf("underflow");
        return -1;
    }else {
        struct node*topnode=s->top;
        int value =topnode->data;
        s->top =topnode->next;
        free(topnode);
        return value;
    }
}

int main(){
    stack s;
    initialize(&s);
    push(&s,1);

    pop(&s);
    return 0;
}