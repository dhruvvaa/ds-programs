//to insert elements at the beginning and end using singly linked list 
#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* top=NULL;

void insertAtBeginning(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=top;
    top=newNode;
}

void insertAtEnd(int val){
    struct Node* newNode=(struct Node*)malloc(sizeof(struct Node));
    newNode->data=val;
    newNode->next=NULL;
    if(top==NULL){
        top=newNode;
        return;
    }
    struct Node* temp=top;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=newNode;
}

void display(){
    struct Node* temp=top;
    if(temp==NULL){
        printf("List Empty\n");
        return;
    }
    printf("Linked List:");
    while(temp!=NULL){
        printf("%d->",temp->data);
    temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    insertAtBeginning(10);
    insertAtBeginning(20);
    insertAtEnd(30);
    insertAtEnd(40);
    display();
    return 0;
}