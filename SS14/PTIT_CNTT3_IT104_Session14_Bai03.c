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

void traverseStack(Stack stack) {
    printf("stack={\n  ");
    Node* current = stack.head;
    if (current == NULL) {
        printf("NULL\n}\n");
        printf("Ngăn xếp trống\n");
        return;
    }
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");

    current = stack.head;
    while (current != NULL) {
        printf("%d\n", current->data);
        current = current->next;
    }
}

int main() {
    Stack s = createStack();

    int n, val;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &val);
        push(&s, val);
    }

    traverseStack(s);
    return 0;
}
