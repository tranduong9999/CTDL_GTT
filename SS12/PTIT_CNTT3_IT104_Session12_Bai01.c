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

void printList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL)
            printf("<->");
        temp = temp->next;
    }
    printf("->NULL\n");
}

int main() {
    Node* head = NULL;
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        int value;
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &value);
        append(&head, value);
    }

    printf("Danh sach lien ket doi:\n");
    printList(head);

    return 0;
}
