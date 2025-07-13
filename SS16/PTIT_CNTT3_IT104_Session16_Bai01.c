#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Queue {
    struct Node* front;
    struct Node* rear;
};

struct Queue* createQueue() {
    struct Queue* q = (struct Queue*) malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

int isEmpty(struct Queue* q) {
    return q->front == NULL;
}

int main() {
    struct Queue* myQueue = createQueue();

    if (isEmpty(myQueue)) {
        printf("Hàng đợi đang trống\n");
    } else {
        printf("Hàng đợi không trống\n");
    }

    free(myQueue);
    return 0;
}
