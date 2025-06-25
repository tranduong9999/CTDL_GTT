#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    int *array;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0) {
        if (n == 0) {
            printf("So luong phan tu phai lon hon 0\n");
        } else {
            printf("So luong phan tu khong duoc am\n");
        }
        return 1;
    }

    array = (int*)malloc(n * sizeof(int));
    if (array == NULL) {
        printf("Khong the cap phat bo nho\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i + 1);
        scanf("%d", &array[i]);
    }

    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d\n", i + 1, array[i]);
    }

    free(array);

    return 0;
}
