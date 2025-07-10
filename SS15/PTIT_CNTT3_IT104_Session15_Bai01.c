#include <stdio.h>
#include <stdlib.h>

typedef struct Queue {
    int* array;
    int front;
    int rear;
    int maxSize;
} Queue;

Queue createQueue(int size) {
    Queue q;
    q.array = (int*)malloc(size * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.maxSize = size;
    return q;
}

void printQueue(Queue q) {
    printf("Queue = {\n");
    printf("  front = %d\n", q.front);
    printf("  rear = %d\n", q.rear);
    printf("  array = [");
    for (int i = 0; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i < q.rear) printf(", ");
    }
    printf("]\n}\n");
}

int main() {
    int maxSize = 5;
    Queue q = createQueue(maxSize);
    printQueue(q);
    free(q.array);
    return 0;
}
