#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct node* createnode(int value);

struct node *insertAtPosition(struct node *last,int data,int pos){
    if(last==NULL){
        if(pos!=1){
            printf("Invalid Position\n");
            return last;
        }
        struct node *newnode=createnode(data);
        last=newnode;
        last->next=last;
        return last;
    }
    struct node *newnode=createnode(data);
    struct node *curr=last->next;
    if(pos==1){
        newnode->next=curr;
        last->next=newnode;
        return last;
    }
    for(int i=1;i<pos-1;++i){
        curr=curr->next;
        if(curr==last->next){
            printf("Invalid Position\n");
            return last;
        }
    }
    newnode->next=curr->next;
    curr->next=newnode;
    if(curr==last)
        last=newnode;
        return last;
    }
    void printList(struct node *last){
        if(last==NULL)
        return;

        struct node *head=last->next;
        while(1){
            printf("%d",head->data);
            head=head->next;
            if(head==last->next)
            break;
        }
        printf("\n");
    }
    struct node* createnode(int value){
        struct node* newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=NULL;
        return newnode;
    }

int main(){
    struct node *first=createnode(2);
    first->next=createnode(3);
    first->next->next=createnode(4);

    struct node *last=first->next->next;
    last->next=first;

    printf("Original List:");
    printList(last);

    int data=5,pos=2;
    last=insertAtPosition(last,data,pos);
    printf("List After Insertion:");
    printList(last);

    return 0;
}