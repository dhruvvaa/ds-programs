#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

void insertatbeginning(struct node** head,int newdata){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=newdata;
    newnode->next=*head;
    *head=newnode;
}

void printlist(struct node* head){
    while(head!=NULL){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}

int main(){
    struct node* head=NULL;
    insertatbeginning(&head,10);
    insertatbeginning(&head,20);
    insertatbeginning(&head,30);
    printlist(head);
    return 0;
}