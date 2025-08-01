#include<stdio.h>
#define max 50
#include<stdlib.h>

int top=-1;
int stack[max];
void push();
void pop();
void display();

void main(){
    int ch;
    system("clear");
    while (1)
    {
        printf("\n_");
        printf("\nStack ADT Operations are:\n");
        printf("___");
        printf("\n\t1.Push");
        printf("\n\t2.Pop");
        printf("\n\t3.Display");
        printf("\n\t4.Exit");
        printf("\nEnter your choice:");
        scanf("%d",&ch);

        switch(ch){
            case1:push();
            break;
            case 2:pop();
            break;
            case 3:display();
            break;
            case 4:exit(0);
            break;
            default:printf("\nWrong Choice");
        }
    }
}

void push(){
    int element;
    if(top==max-1)
    printf("\nStack Overflow\n");
    else{
        printf("\nEnter element to be inserted:");
        scanf("%d",&element);
        top=top+1;
        stack[top]=element;
    }
}

void pop(){
    if(top==-1)
    printf("\nStack Underflow\n");
    else{
        printf("\nDeleted element is:%d\n",stack[top]);
        top=top-1;
    }
}

void display(){
    int i;
    if(top==-1)
    printf("\nStack Empty");
    else{
        printf("\nStack elements are:\n");
        for(i=top;i>=0;i--)
        printf("\t%d",stack[i]);
    }
}