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

Node* insertAtPosition(Node* head, int value, int position) {
    Node* newNode = createNode(value);
    if (position <= 0 || head == NULL) {
        newNode->next = head;
        return newNode;
    }

    Node* temp = head;
    int i = 0;
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    return head;
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
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    printf("Danh sach ban dau:\n");
    printList(head);

    int value, position;
    printf("\nNhap gia tri muon chen: ");
    scanf("%d", &value);
    printf("Nhap vi tri muon chen (bat dau tu 0): ");
    scanf("%d", &position);

    head = insertAtPosition(head, value, position);

    printf("\nDanh sach sau khi chen:\n");
    printList(head);

    freeList(head);
    return 0;
}
