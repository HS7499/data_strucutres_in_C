#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char stack[128];
int top=-1;
void push(char m){
    if (top==128 -1){
        return;

    }
    top++;
    stack[top]=m;
}

void pop(){
    if (top==-1){
        return ;
        //empty list
    }
    top--;
}

int isempty(int top){
    if (top ==-1){
        return 1;

    }else {
        return 0;
    }
}


int main(){
    int n;
    scanf("%d",&n);
    int k = 0;
    for (int i=0;i<n;i++){
        char str[128];
        scanf("%s",&str);
        for (int j=0;j<strlen(str);j++){
            char m = str[j];
            
            if (str[j]=='('){
                push(m);
            }else if (str[j]==')'){
                if (isempty(top)){
                    k = 1;
                    printf("No\n");
                    break;
                }
                else{
                    pop();
                }
            }
        }
        if(k == 0){
        if (isempty(top)){
            printf("Yes\n");
        }else {
            printf("No\n");
        }
        }
        top = -1;
    }
}

