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

int searchList(Node* head, int target) {
    while (head != NULL) {
        if (head->data == target)
            return 1;
        head = head->next;
    }
    return 0;
}

int main() {
    Node* head = createNode(1);
    head->next = createNode(2);
    head->next->next = createNode(3);
    head->next->next->next = createNode(4);
    head->next->next->next->next = createNode(5);

    int number;
    printf("Nhap so can tim: ");
    scanf("%d", &number);

    if (searchList(head, number))
        printf("True\n");
    else
        printf("False\n");

    Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }

    return 0;
}
