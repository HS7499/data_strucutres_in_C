#include<stdio.h>
#include<math.h>
#include<stdlib.h>

int compare(const void*a,const void*b){
    int A=*((int*)a); //typecasting to int* and getting value
    int B=*((int*)b);
    return abs(A)-abs(B);
}

int main(){

    int i,arr[]={-31,22,-1,30,-6,4};
    qsort(arr,6,sizeof(int),compare);
    for (i=0;i<6;i++){
        printf("%d ",arr[i]);
    }
}