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
        s->data[++s->top] = value;
    }
}

int pop(Stack* s) {
    if (s->top == -1) {
        return -1;
    }
    return s->data[s->top--];
}

void reverseArray(int arr[], int n) {
    Stack s = createStack(n);
    for (int i = 0; i < n; i++) {
        push(&s, arr[i]);
    }
    for (int i = 0; i < n; i++) {
        arr[i] = pop(&s);
    }
    free(s.data);
}

void printArray(int arr[], int n) {
    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf("]\n");
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0 || n > 1000) {
        printf("Input không hợp lệ\n");
        return 0;
    }
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printArray(arr, n);
    reverseArray(arr, n);
    printArray(arr, n);

    return 0;
}
