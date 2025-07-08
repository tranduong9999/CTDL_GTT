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

int main() {
    Stack stack = createStack(5);
    int value;

    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < 5; i++) {
        scanf("%d", &value);
        push(&stack, value);
    }

    printf("\nstack={\n");
    printf("    elements: [");
    for (int i = 0; i <= stack.top; i++) {
        printf("%d", stack.data[i]);
        if (i < stack.top) printf(", ");
    }
    printf("],\n");
    printf("    top: %d,\n", stack.top);
    printf("    cap: %d\n", stack.maxSize);
    printf("}\n");

    return 0;
}

