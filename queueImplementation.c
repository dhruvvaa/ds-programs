#include<stdio.h>
#define max 50

void insert();
void delete();
void display();

int queue_array[max];
int rear=-1;
int front=-1;

int main(){
    int choice;
    while(1){
        printf("\n1.Inert element to queue\n");
        printf("\n2.Delete element from queue\n");
        printf("\n3.Display all elements of queue\n");
        printf("4.Quit\n");
        printf("\nEnter your choice:");
        scanf("%d",&choice);

        switch(choice){
            case 1:insert();
            break;
            case 2:delete();
            break;
            case 3:display();
            break;
            case 4:exit(1);
            break;
            default:printf("Wrong Choice\n");
        }
    }
}

void insert(){
    int add_item;
    if(rear==max-1)
    printf("\nQueue Overflow\n");
    else{
        if(front==-1)
        front=0;
        printf("Insert the element in queue:");
        scanf("%d",&add_item);
        rear=rear+1;
        queue_array[rear]=add_item;
    }
}

void delete(){
    if(front==-1||front>rear){
        printf("\nQueue Underflow\n");
        return;
    }
    else{
        printf("\nElement deleted from queue is:%d",queue_array[front]);
        front=front+1;
    }
}

void display(){
    int i;
    if(front==-1)
    printf("\nQueue is empty\n");
    else{
        printf("\nQueue is:\n");
        for(i=front;i<=rear;i++)
        printf("%d",queue_array[i]);
        printf("\n");
    }
}