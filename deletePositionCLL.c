#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* deleteSpecificNode(struct Node* last, int key) {
    if (last == NULL) {
        printf("List is empty, nothing to delete.\n");
        return NULL;
    }

    struct Node* curr = last->next;
    struct Node* prev = last;

    if (curr == last && curr->data == key) {
        free(curr);
        last = NULL;
        return last;
    }

    if (curr->data == key) {
        last->next = curr->next;
        free(curr);
        return last;
    }

    while (curr != last && curr->data != key) {
        prev = curr;
        curr = curr->next;
    }

    if (curr->data == key) {
        prev->next = curr->next;
        if (curr == last) {
            last = prev;
        }
        free(curr);
    } else {
        printf("Node with data %d not found.\n", key);
    }

    return last;
}

void printList(struct Node* last) {
    if (last == NULL) {
        printf("List is Empty");
        return;
    }

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

    int key = 3;
    last = deleteSpecificNode(last, key);

    printf("List after deleting node %d: ", key);
    printList(last);

    return 0;
}