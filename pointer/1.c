 //pointers are variables that stores the adrress of another varible 
#include <stdio.h>
int main(){

    int a=5; //normal varible
    int* p;
    p= &a;
    printf("%d\n",&a);
    printf("%p\n\n",p); // p = address 
    printf("%d\n",*p);

    //defrencing 
    *p= 20;
    
    //or 

    int b=20;
    *p = b;
    //now value is modified but pointer will still point towards the same memory address




    return 0;

}  
