//Function pointers and callbacks
#include<stdio.h>

void a(){
    printf("hello\n");

}

void B(void (*ptr)()){ //function pointer as argumnet
    ptr(); //call back function that "ptr" points to
}
int main(){

    void(*p)()=a; // can aslo be retruned as B(a); 
    B(p);
}
//when refrence of a function is used to call a particular function then
//it is called callback function

