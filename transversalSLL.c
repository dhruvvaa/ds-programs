#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data; 
    newNode->next = NULL;  
    return newNode;
}

void traverseList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);  
        head = head->next;            
    }
    printf("NULL\n");                  
}

int main() {
    struct Node* head = createNode(10);
    head->next = createNode(20);
    head->next->next = createNode(30);
    head->next->next->next = createNode(40);

    traverseList(head);
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}