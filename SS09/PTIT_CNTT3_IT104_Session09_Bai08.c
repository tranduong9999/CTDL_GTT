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

Node* deleteAtPosition(Node* head, int position) {
    if (head == NULL || position < 0) return head;

    Node* temp = head;

    if (position == 0) {
        head = head->next;
        free(temp);
        return head;
    }

    int i = 0;
    while (i < position - 1 && temp->next != NULL) {
        temp = temp->next;
        i++;
    }

    if (temp->next == NULL) {
        printf("Vi tri vuot qua do dai danh sach.\n");
        return head;
    }

    Node* toDelete = temp->next;
    temp->next = toDelete->next;
    free(toDelete);

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

    int position;
    printf("\nNhap vi tri muon xoa (bat dau tu 0): ");
    scanf("%d", &position);

    head = deleteAtPosition(head, position);

    printf("\nDanh sach sau khi xoa:\n");
    printList(head);

    freeList(head);
    return 0;
}
