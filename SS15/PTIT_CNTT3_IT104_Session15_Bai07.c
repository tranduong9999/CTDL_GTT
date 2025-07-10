#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Customer {
    char name[31]; 
};

struct Queue {
    struct Customer customers[100];
    int front;
    int rear;
    int size;
    int capacity;
};

void initQueue(struct Queue *q, int cap) {
    q->front = 0;
    q->rear = -1;
    q->size = 0;
    q->capacity = cap;
}

int isEmpty(struct Queue *q) {
    return q->size == 0;
}

int isFull(struct Queue *q) {
    return q->size == q->capacity;
}

void enqueue(struct Queue *q, char name[]) {
    if (isFull(q)) {
        printf("Hàng đợi đầy. Không thể thêm khách mới.\n");
        return;
    }
    q->rear = (q->rear + 1) % q->capacity;
    strcpy(q->customers[q->rear].name, name);
    q->size++;
    printf("Đã thêm khách \"%s\" vào hàng đợi.\n", name);
}

void dequeue(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng. Không có khách để phục vụ.\n");
        return;
    }
    printf("Phục vụ khách: %s\n", q->customers[q->front].name);
    q->front = (q->front + 1) % q->capacity;
    q->size--;
}

void display(struct Queue *q) {
    if (isEmpty(q)) {
        printf("Hàng đợi rỗng.\n");
        return;
    }
    printf("Danh sách khách đang chờ:\n");
    for (int i = 0; i < q->size; i++) {
        int idx = (q->front + i) % q->capacity;
        printf("%d. %s\n", i + 1, q->customers[idx].name);
    }
}

int main() {
    struct Queue q;
    int maxSize = 5;
    initQueue(&q, maxSize);

    int choice;
    char name[31];

    do {
        printf("\n--- QUẦY BÁN VÉ ---\n");
        printf("1. Thêm khách hàng mới\n");
        printf("2. Phục vụ khách\n");
        printf("3. Hiển thị danh sách chờ\n");
        printf("4. Thoát\n");
        printf("Chọn thao tác: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Nhập tên khách hàng: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0';
                enqueue(&q, name);
                break;
            case 2:
                dequeue(&q);
                break;
            case 3:
                display(&q);
                break;
            case 4:
                printf("Thoát chương trình.\n");
                break;
            default:
                printf("Lựa chọn không hợp lệ.\n");
        }
    } while (choice != 4);

    return 0;
}
