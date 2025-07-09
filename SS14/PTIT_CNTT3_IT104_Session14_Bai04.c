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

int pop(Stack* stack) {
    if (stack->head == NULL) {
        printf("Ngăn xếp trống\n");
        return -1;
    }
    Node* temp = stack->head;
    int value = temp->data;
    stack->head = temp->next;
    free(temp);
    return value;
}

void printStack(Stack stack) {
    printf("stack={\n   ");
    Node* current = stack.head;
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

    pop(&s);
    printStack(s);

    while (pop(&s) != -1);
    printStack(s);

    return 0;
}
