#include<stdio.h>
#include<stdlib.h>
//using malloc and other is free
int main(){

    int size;
    int *ptr;
    //entering the size of array
    scanf("%d",&size);

    ptr=(int *)malloc(size*sizeof(int));



    return 0;
}