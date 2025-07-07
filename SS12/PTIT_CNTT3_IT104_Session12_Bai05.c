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

void deleteValue(Node** head, int target) {
    Node* temp = *head;
    while (temp != NULL) {
        if (temp->data == target) {
            Node* toDelete = temp;
            if (temp->prev)
                temp->prev->next = temp->next;
            else
                *head = temp->next;
            if (temp->next)
                temp->next->prev = temp->prev;
            temp = temp->next;
            free(toDelete);
        } else {
            temp = temp->next;
        }
    }
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("<->");
        head = head->next;
    }
    printf("->NULL\n");
}

int main() {
    Node* head = NULL;
    append(&head, 5);
    append(&head, 4);
    append(&head, 3);
    append(&head, 5);
    append(&head, 2);
    append(&head, 1);
    append(&head, 5);

    int x;
    scanf("%d", &x);

    deleteValue(&head, x);
    printList(head);
    return 0;
}
