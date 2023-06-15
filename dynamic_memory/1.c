//acessing memory in heap
#include<stdio.h>
#include<stdlib.h>

int main(){

    int a;//goes in stack 
    int *p;
    p=(int*)malloc(sizeof(int));
    *p=10;
    free(p); //for freeing up the memory after it is used since it cnnot automaticallly cleared
    p=(int*)malloc(20*sizeof(int)); // malloc provides a void pointer 

    return 0;
}

// in c++

//we use  p =new int; for intger type pointer memory in heap and 
//p=new int[20] for allotation of array in heap
//delete p; for clearing a memory