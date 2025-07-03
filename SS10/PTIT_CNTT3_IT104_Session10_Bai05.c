#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    while (head != NULL) {
        printf("%d", head->data);
        if (head->next != NULL)
            printf("->");
        head = head->next;
    }
    printf("->NULL\n");
}

void deleteValue(Node** head, int value) {
    while (*head != NULL && (*head)->data == value) {
        Node* temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    Node* current = *head;
    while (current != NULL && current->next != NULL) {
        if (current->next->data == value) {
            Node* temp = current->next;
            current->next = current->next->next;
            free(temp);
        } else {
            current = current->next;
        }
    }
}

void freeList(Node* head) {
    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}

int main() {
    Node* head = createNode(5);
    head->next = createNode(4);
    head->next->next = createNode(3);
    head->next->next->next = createNode(5);
    head->next->next->next->next = createNode(2);
    head->next->next->next->next->next = createNode(1);
    head->next->next->next->next->next->next = createNode(5);

    printList(head);

    int value;
    scanf("%d", &value);

    deleteValue(&head, value);

    printList(head);
    freeList(head);
    return 0;
}
