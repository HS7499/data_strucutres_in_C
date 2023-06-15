#include<stdio.h>
#include<stdlib.h>
char str[128];


int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        gets(str);
    
        for (int j=0;str[j]!='\0';j++){
        printf("%c",str[j]);
    }
    }
}