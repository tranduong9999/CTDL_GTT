#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = NULL;
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

int search(Node* head, int target) {
    Node* temp = head;
    while (temp != NULL) {
        if (temp->data == target)
            return 1;
        temp = temp->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    append(&head, 1);
    append(&head, 2);
    append(&head, 3);
    append(&head, 4);
    append(&head, 5);

    int x;
    printf("Nhap so can tim: ");
    scanf("%d", &x);

    if (search(head, x))
        printf("True\n");
    else
        printf("False\n");

    return 0;
}
