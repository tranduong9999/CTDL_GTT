#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* data;
    int top;
    int maxSize;
} Stack;

Stack createStack(int size) {
    Stack s;
    s.data = (int*)malloc(size * sizeof(int));
    s.top = -1;
    s.maxSize = size;
    return s;
}

void push(Stack* s, int value) {
    if (s->top < s->maxSize - 1) {
        s->top++;
        s->data[s->top] = value;
    }
}

int pop(Stack* s) {
    if (s->top == -1) {
        printf("No element in stack\n");
        return -1;
    }
    int value = s->data[s->top];
    s->top--;
    return value;
}

void printStack(Stack s) {
    printf("stack={\n");
    printf("    elements: [");
    for (int i = 0; i <= s.top; i++) {
        printf("%d", s.data[i]);
        if (i < s.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", s.top);
    printf("    cap: %d\n", s.maxSize);
    printf("}\n");
}

int main() {
    Stack stack = createStack(5);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printStack(stack);

    int popped = pop(&stack);
    if (popped != -1) {
        printf("%d\n", popped);
    }

    printStack(stack);

    while (pop(&stack) != -1);

    pop(&stack);
    return 0;
}
