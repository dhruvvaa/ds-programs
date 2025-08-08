#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

struct Node* deleteNode(struct Node* head, int position) {
    if (head == NULL) {
        printf("The list is empty.\n");
        return head;
    }

    struct Node* temp = head;

    if (position == 1) {
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = NULL;
    for (int i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position %d is out of bounds.\n", position);
        return head;
    }

    prev->next = temp->next;
    free(temp);

    return head;
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}
int main() {
    struct Node* head = newNode(2);
    head->next = newNode(3);
    head->next->next = newNode(4);
    head->next->next->next = newNode(5);

    printf("Original list: ");
    printList(head);

    int position = 2;
    head = deleteNode(head, position);

    printf("List after deletion: ");
    printList(head);

    while (head != NULL) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}