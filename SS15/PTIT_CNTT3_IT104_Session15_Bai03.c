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

int isEmpty(Queue q) {
    return q.rear < q.front;
}

void printQueue(Queue q) {
    printf("queue = {\n");
    printf("  array = [");
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d", q.array[i]);
        if (i < q.rear) printf(", ");
    }
    printf("],\n");
    printf("  front = %d,\n", q.front);
    printf("  rear = %d,\n", q.rear);
    printf("  capacity = %d\n", q.maxSize);
    printf("}\n");
}

int main() {
    Queue q1 = createQueue(5);
    printQueue(q1);
    printf("\n%s\n\n", isEmpty(q1) ? "true" : "false");

    Queue q2 = createQueue(5);
    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    printQueue(q2);
    printf("\n%s\n", isEmpty(q2) ? "true" : "false");

    free(q1.array);
    free(q2.array);
    return 0;
}
