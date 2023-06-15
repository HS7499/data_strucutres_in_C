//incrementing the array by one unit increments the address by size of the data type 


//pointers as retrun function 
#include<stdio.h>
#include<stdlib.h>

// int Add(int a,int b ){//called function
//     int c = a+b;
//     return c;

// }
// int main(){ //calling function
//     int a= 2 , b=4;
//     int c= Add(a,b); // value of a is copied to a of add

//     printf("%d\n",c);

// }
//above stores both the  a  and b of Add and main at different address

//using pointer as function return 

int *Add(int* a,int* b ){//called function - return pointer to integer 
    int* c=(int*)malloc(sizeof(int));
    *c = (*a)+(*b);
    return c;

}
int main(){ //calling function
    int a= 2 , b=4;
    int* ptr = Add(&a,&b); // a and b are local to main

    printf("%d\n",*ptr);

}