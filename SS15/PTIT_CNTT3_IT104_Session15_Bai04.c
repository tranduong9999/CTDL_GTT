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

void viewQueue(Queue q) {
    if (isEmpty(q)) {
        printf("queue is empty\n");
        return;
    }
    for (int i = q.front; i <= q.rear; i++) {
        printf("%d\n", q.array[i]);
    }
}

int main() {
    Queue q1 = createQueue(5);
    viewQueue(q1);  // In ra "queue is empty"

    Queue q2 = createQueue(5);
    q2.rear = 2;
    q2.array[0] = 1;
    q2.array[1] = 2;
    q2.array[2] = 5;
    viewQueue(q2);  // In ra 1 2 5

    free(q1.array);
    free(q2.array);
    return 0;
}
