#include<stdio.h>
#include<stdlib.h>

int main(){

    int a = 1025;
    int *p;
    p=&a;
    printf("size = %d\n ",sizeof(int ));
    printf("value is %d , address is %d\n",*p, p);

    //void pointer  - geneirc pointer 
    void *p0;
    p0 =p;
    printf("address = %d",p0); 
    // connot derefernce this particular pointer 


    return 0;


    

}