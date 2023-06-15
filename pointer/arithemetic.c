#include<stdio.h>
#include<stdlib.h>

int main(){

    char a =10;
    int *p;

    p=&a;
    //pointer arithemtic

    printf("address p is %d\n",p);
    printf("size of integer is %d bytes\n",sizeof(int));
    printf("address p+1 is %d\n",p+1);

    return 0;
}

// we can use name of the array just like pointer
