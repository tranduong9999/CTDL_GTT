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
    printf("},\n\n");
}

void enqueue(Queue* q, int value) {
    if (q->rear >= q->maxSize - 1) {
        printf("queue is full\n\n");
        return;
    }
    q->rear++;
    q->array[q->rear] = value;
    printQueue(*q);
}

int main() {
    int size, value;
    printf("Nhập kích thước hàng đợi: ");
    scanf("%d", &size);

    Queue q = createQueue(size);
    printQueue(q);

    for (int i = 0; i < 5; i++) {
        printf("Nhập giá trị để thêm vào hàng đợi: ");
        scanf("%d", &value);
        enqueue(&q, value);
    }

    free(q.array);
    return 0;
}
