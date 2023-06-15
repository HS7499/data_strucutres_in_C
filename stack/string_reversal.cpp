#include<stdio.h>
#include<stack>// stack form standard library template(STL)
#include<cstring>
using namespace std;

void reverse(char*C,int n){

    stack<char> S;
    for (int i=0;i<n;i++){
        S.push(C[i]);
    }

    for (int i =0;i<n;i++){
        C[i]= S.top(); //overwrite
        S.pop(); //perform pop
    }
}  
int main(){
    char C[51];
    getchar();
    reverse(C,strlen(C));
    printf("%s ",C);


}