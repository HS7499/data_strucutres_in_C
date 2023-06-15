#include<stdio.h>
#include<stdlib.h>


void print (char* C)
{   
    int i = 0;
    while (C[i] != NULL) 
    {
        printf("%c",C[i]);
        i++;
    }
    printf("\n");  
}
int main(){

    char C[20]="hello"; // string gets stored in the spcae for array 
    // char *C= "hello"; // string gets stored as compile time constant and we cannot make change in the string 

    print(C);
}
//if int(*p)[3] =B;

//the diffrence between *B and &B is that *B is returing the apointer of 1D array of three integers 
// while &b is returing pointer to an integer 