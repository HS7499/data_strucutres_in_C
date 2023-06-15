//calloc also intializes the intial value at the memory as 0
//realloc maybe used for incrseing the size of the existing allocated memory
#include<stdio.h>
#include<stdlib.h>

int main(){

    int n ; //local var
    scanf("%d",&n);
    int *A =(int *)malloc(n*sizeof(int)); //dyanamiclly allocated array
    for (int i=0;i<n;i++){
        A[i]= i+1;
    }
    //free(A);
    //A =NULL; //after free,adjust the pointer to NUll
    int *B=(int *)realloc(A,(n/2)*sizeof(int));
    for (int i =0;i<2*n;i++)
    {

        printf("%d ",B[i]);
    }
}
//In realloc if frist argument is o then it is same as freeing 
//if frist argument is NUll then its equivalent to calling malloc 