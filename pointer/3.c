#include<stdio.h>
#include<stdlib.h>

void increment(int *p){
    *p = (*p) +1 ;
}

int main() {

    int a ;
    a = 10;
    int *p;
    p=&a;
    increment(&a);
    printf("%d\n",a);

    return 0 ;
}