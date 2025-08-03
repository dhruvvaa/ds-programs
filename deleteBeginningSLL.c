#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* createNode(int new_data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->data = new_data;
    newNode->next = NULL;
    return newNode;
}

struct Node* deleteHead(struct Node* head){
    if (head == NULL) {
        printf("The list is already empty.\n");
        return NULL;
    }

    struct Node* temp = head;
    head = head->next;
    free(temp);
    return head;
}

void printList(struct Node* curr) {
    while (curr != NULL) {
        printf("%d -> ", curr->data);
        curr = curr->next;
    }
    printf("NULL\n");
}

int main() {
    struct Node* head = createNode(3);
    head->next = createNode(12);
    head->next->next = createNode(15);
    head->next->next->next = createNode(18);

    printf("Original list:\n");
    printList(head);
    head = deleteHead(head);
    printf("\nList after deleting the head:\n");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}