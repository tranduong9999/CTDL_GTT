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

void push(Stack* stack, int value) {
    Node* newNode = createNode(value);
    newNode->next = stack->head;
    stack->head = newNode;
}

void printStack(Stack stack) {
    printf("stack = {\n   ");
    Node* current = stack.head;
    while (current != NULL) {
        printf("%d->", current->data);
        current = current->next;
    }
    printf("NULL\n}\n");
}

int main() {
    Stack myStack = createStack();

    push(&myStack, 5);
    push(&myStack, 4);
    push(&myStack, 3);
    push(&myStack, 2);
    push(&myStack, 1);

    printStack(myStack);

    int value;
    printf("Nhập giá trị cần thêm vào ngăn xếp: ");
    scanf("%d", &value);

    push(&myStack, value);

    printStack(myStack);

    return 0;
}
