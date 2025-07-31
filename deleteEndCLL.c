#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteLastNode(struct Node* last) {
    if (last == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }
    struct Node* head = last->next;

    if (head == last) {
        free(last);
        last = NULL;
        return last;
    }

    struct Node* curr = head;
    while (curr->next != last) {
        curr = curr->next;
    }
    curr->next = head;
    free(last);
    last = curr;

    return last;
}

void printList(struct Node* last) {
    if (last == NULL) return;

    struct Node* head = last->next;
    while (1) {
        printf("%d ", head->data);
        head = head->next;
        if (head == last->next) break;
    }
    printf("\n");
}

struct Node* createNode(int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

int main() {
     struct Node* first = createNode(2);
    first->next = createNode(3);
    first->next->next = createNode(4);

    struct Node* last = first->next->next;
    last->next = first;

    printf("Original list: ");
    printList(last);
    last = deleteLastNode(last);
    printf("List after deleting last node: ");
    printList(last);

    return 0;
}