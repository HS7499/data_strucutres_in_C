#include<stdlib.h>
#include<stdio.h>


char arr[128];
int top;

void push(int x){
    if (top==128-1){
        return;
    }
    ++top;
}

void pop(int x){
    if (top==-1){
        return ;
    }
    top=top-1;

}

int isempty(){
    if(top == -1){
        return 1;
    }
    return 0;
}


int main(){
    int n;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        int top=-1;
        char arr[128];
        scanf("%s",arr);
        int j =0;
        while (arr[j]!='#'){

            if (arr[i]=='('){
            push(1);
        }
        else if (arr[i]==')'){
            if(isempty){
                printf("No\n");
                break;
            }
            else{
                pop(1);
            }    
                
        }
       
    }
    printf("%d",top);

        }
        
    //for every string i am getting top value as -1
    //i am not able to get multiple string input and then go thorough the string;
    
}
