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

void printStackInfo(Stack s) {
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

void viewStack(Stack s) {
    for (int i = s.top; i >= 0; i--) {
        printf("%d\n", s.data[i]);
    }
}

int main() {
    Stack stack = createStack(5);

    push(&stack, 10);
    push(&stack, 20);
    push(&stack, 30);
    push(&stack, 40);
    push(&stack, 50);

    printStackInfo(stack);
    viewStack(stack);

    return 0;
}
