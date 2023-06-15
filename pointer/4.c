#include<stdio.h>
#include<stdlib.h>
//if p = &A 
// then address =  &A[i] and value = A[i]
// if p = A
//then address = A+i and value = *(A+i)

// now arryas as functional 

int sumofelements(int* A,int  size)// int*A or in A[] is the same
{

    int i ,sum =0 ;
    for (i=0;i<size;i++){
        sum=sum+A[i]; // A[i] is *(A+i)
    }
    return sum;
}


int main(){

    int A[]={1,2,3,4,5};
    int size =sizeof(A)/sizeof(A[0]);
    int total = sumofelements(A,size); // A can be used as &A[0]
    printf("%d\n",total);
    
    return 0;

}