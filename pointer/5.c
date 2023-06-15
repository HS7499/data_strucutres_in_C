#include<stdio.h>
#include<stdlib.h>

int main(){
 
    int A[]={2,3,4,5,6};
    int i;
    int *p =A;
    for (i=0;i<5;i++){

        printf("%p\n",A+i);
        printf("%d\n",*(A+i));
    }

    return 0;
}