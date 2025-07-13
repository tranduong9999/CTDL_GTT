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
    struct Queue* q = (struct Queue*)malloc(sizeof(struct Queue));
    q->front = NULL;
    q->rear = NULL;
    return q;
}

void viewFront(struct Queue* q) {
    if (q->front == NULL) {
        printf("queue is empty\n");
    } else {
        printf("%d\n", q->front->data);
    }
}

int main() {
    struct Queue* q = createQueue();

    viewFront(q);

    struct Node* n1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* n3 = (struct Node*)malloc(sizeof(struct Node));
    n1->data = 1; n1->next = n2;
    n2->data = 2; n2->next = n3;
    n3->data = 5; n3->next = NULL;
    q->front = n1;
    q->rear = n3;

    viewFront(q);

    return 0;
}
