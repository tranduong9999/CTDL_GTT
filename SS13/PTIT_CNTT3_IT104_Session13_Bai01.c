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

int main() {
    Stack myStack = createStack(5);
    printf("Stack created with max size: %d\n", myStack.maxSize);
    return 0;
}
