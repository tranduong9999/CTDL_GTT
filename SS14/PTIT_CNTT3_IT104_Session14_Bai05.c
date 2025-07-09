#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct Stack {
    Node* head;
} Stack;

Node* createNode(int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}

Stack createStack() {
    Stack s;
    s.head = NULL;
    return s;
}

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

int peek(Stack stack) {
    if (stack.head == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    return stack.head->data;
}

void printStack(Stack stack) {
    printf("stack={\n  ");
    Node* current = stack.head;
    if (current == NULL) {
        printf("NULL\n}\n");
        return;
    }
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");
}

int main() {
    Stack s = createStack();

    push(&s, 5);
    push(&s, 4);
    push(&s, 3);
    push(&s, 2);
    push(&s, 1);

    printStack(s);
    printf("%d\n", peek(s));

    Stack empty = createStack();
    printStack(empty);
    printf("%d\n", peek(empty));

    return 0;
}
