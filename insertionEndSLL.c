#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void addlast(struct node** head,int val){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=val;
    newnode->next=NULL;
    if(*head==NULL)
    *head=newnode;
    else{
        struct node* lastnode=*head;
        while(lastnode->next!=NULL){
            lastnode=lastnode->next;
        }
        lastnode->next=newnode;
    }
}

void printlist(struct node* head){
    struct node* temp=head;
    while(temp!=NULL){
        printf("%d->",temp->data);
        temp=temp->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head=NULL;
    addlast(&head,10);
    addlast(&head,20);
    addlast(&head,30);
    printlist(head);
    return 0;
}