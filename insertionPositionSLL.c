#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node* next;
};

struct node* createnode(int x){
    struct node* newnode=(struct node*)malloc(sizeof(struct node));
    if(!newnode){
        printf("Memory allocation failed\n");
        exit(1);
    }
    newnode->data=x;
    newnode->next=NULL;
    return newnode;
}

void printlist(struct node* head){
    struct node* curr=head;
    while(curr!=NULL){
        printf("%d->",curr->data);
        curr=curr->next;
    }
    printf("NULL\n");
}

struct node* insertPos(struct node* head, int pos, int data){
    if(pos<1){
        printf("Invalid Position\n");
        return head;
    }
    if(pos==1){
        struct node* newnode=createnode(data);
        newnode->next=head;
        return newnode;
    }
    struct node* curr=head;
    for(int i=1;i<pos-1&&curr!=NULL;i++){
        curr=curr->next;
    }
    if(curr==NULL){
        printf("Position is out of bound\n");
        return head;
    }
    struct node* newnode=createnode(data);
    newnode->next=curr->next;
    curr->next=newnode;
    return head;
}

int main(){
    struct node* head=createnode(3);
    head->next=createnode(5);
    head->next->next=createnode(8);
    head->next->next->next=createnode(10);

    printf("Original List:\n");
    printlist(head);
    int data=12,pos=3;
    head=insertPos(head,pos,data);
    printf("\nList after insertion:\n");
    printlist(head);

    while(head!=NULL){
        struct node* temp=head;
        head=head->next;
        free(temp);
    }

    return 0;
}