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

int getLength(Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

void printMiddle(Node* head) {
    int len = getLength(head);
    int midPos = len / 2;
    if (len % 2 == 0)
        midPos++;
    else
        midPos++;

    Node* temp = head;
    for (int i = 1; i < midPos; i++)
        temp = temp->next;

    printf("Node %d: %d\n", midPos, temp->data);
}

int main() {
    Node* head = NULL;
    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 2);
    append(&head, 1);

    printMiddle(head);
    return 0;
}
