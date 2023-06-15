#include<stdio.h>
#include<stdlib.h>
void print(char*name){
    printf("hello %s\n",name);
}
int main(){
    void (*ptr)(char*);
    ptr=print;//function name will return as pointer 
    ptr("Tom");//de-referencing and executing the function
} 