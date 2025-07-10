#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *array;
    int front;
    int rear;
    int capacity;
} Queue;

Queue createQueue(int size) {
    Queue q;
    q.array = (int *)malloc(size * sizeof(int));
    q.front = 0;
    q.rear = -1;
    q.capacity = size;
    return q;
}

int isEmpty(Queue *q) {
    return q->rear < q->front;
}

void enqueue(Queue *q, int value) {
    if (q->rear + 1 < q->capacity) {
        q->rear++;
        q->array[q->rear] = value;
    }
}

int dequeue(Queue *q) {
    if (isEmpty(q)) return -1;
    return q->array[q->front++];
}

int main() {
    int n;
    scanf("%d", &n);

    if (n <= 1) {
        printf("True\n");
        return 0;
    }

    Queue q = createQueue(n);
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        enqueue(&q, x);
    }

    int isIncreasing = 1;
    int prev = dequeue(&q);
    while (!isEmpty(&q)) {
        int curr = dequeue(&q);
        if (curr - prev != 1) {
            isIncreasing = 0;
            break;
        }
        prev = curr;
    }

    printf(isIncreasing ? "True\n" : "False\n");

    free(q.array);
    return 0;
}
