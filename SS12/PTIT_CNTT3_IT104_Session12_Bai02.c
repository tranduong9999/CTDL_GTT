#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = value;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int value) {
    Node* newNode = createNode(value);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* temp = *head;
    while (temp->next != NULL)
        temp = temp->next;
    temp->next = newNode;
    newNode->prev = temp;
}

void printReverse(Node* head) {
    if (head == NULL)
        return;
    while (head->next != NULL)
        head = head->next;
    while (head != NULL) {
        printf("data: %d\n", head->data);
        head = head->prev;
    }
}

int main() {
    Node* head = NULL;
    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);
    printReverse(head);
    return 0;
}
