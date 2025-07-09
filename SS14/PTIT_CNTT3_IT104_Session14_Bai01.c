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

typedef struct Stack {
    Node* head;
} Stack;

Stack createStack() {
    Stack s;
    s.head = NULL;
    return s;
}

int main() {
    Stack myStack = createStack();
    if (myStack.head == NULL) {
        printf("Ngăn xếp được khởi tạo thành công với head = NULL\n");
    }
    return 0;
}
