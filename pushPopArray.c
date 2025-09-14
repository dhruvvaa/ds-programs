//stack implemantation using array
#include<stdio.h>
#define SIZE 5

int stack[SIZE],top=-1;

void push(int val){
    if(top==SIZE-1)
        printf("STACK OVERFLOW\n");
    else
        stack[++top]=val;
}

void pop(){
    if(top==-1)
        printf("STACK UNDERFLOW\n");
    else
        top--;
}

void display(){
    for(int i=top;i>=0;i--){
        printf("%d ",stack[i]);
    }
    printf("\n");
}

int main(){
    push(10);
    push(20);
    push(30);
    display();
    pop();
    display();
    return 0;
}