#include<stdio.h>
#include<stdlib.h>

int main(){

    int a = 5;
    int *p  = &a;
    *p = 6;
    int **q =&p;
    int ***r =&q;

    printf("%d\n",*p);
    printf("%d\n",*q);
    ***r= 10;

    printf("%d\n",a);
    **q=*p+2;
    printf("%d\n",a);
    return 0;


    

}