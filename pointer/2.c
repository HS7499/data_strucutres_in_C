//pointer type 
//since we also defrence a variable we need different type of pointers
#include<stdio.h>
#include<stdlib.h>

int main(){

    int a = 1025;
    int *p;
    p=&a;
    printf("size = %d\n ",sizeof(int ));
    printf("%d , %d\n",*p, p);

    
    char *p0;
    p0 = (char*)p;
    printf("size = %d\n ",sizeof(char ));
    printf("%d , %d\n",*p0, p0);
    
    // we can clearly see the difference and similarity in the output
    //we can only add or subtract  
    
    return 0;

}