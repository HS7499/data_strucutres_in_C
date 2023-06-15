 #include<stdio.h>
 #include<stdlib.h>

int add(int a,int b){
    return a+b;
}


int main(){

    int c;
    int (*p)(int,int);
    p=&add;//function name will return as pointer
    c=(*p)(2,4); //de-referencing and executing the function.
    printf("%d\n",c);

 }