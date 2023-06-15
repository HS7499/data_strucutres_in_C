#include<stdio.h>
#include<stdlib.h>

#define max_size 101

int A[max_size];
int top=-1;

void push(int x){
    if (top == max_size -1){
        printf("overflow");
        return;
    }
    A[++top]=x;

}

void pop(){
    if(top==-1){
        printf("empty");
        return;
    }
    top--;

}

int Top(){
    return A[top];

}

void print(){
    int i ;
    for (i=0;i<=top;i++){
        printf("%d ",A[i]);
        }
        printf("\n");

    }


int main()
{
    push(2);print();
    push(5);print();
    push(6);print();
    pop();print();
    push(12);print();
}