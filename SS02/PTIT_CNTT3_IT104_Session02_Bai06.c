#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    int *array;

    printf("Nhap so luong phan tu ban dau: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
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

    printf("Nhap so luong phan tu muon them: ");
    scanf("%d", &m);

    if (m < 0 || (n + m) >= 1000) {
        printf("So luong phan tu them khong hop le\n");
        free(array);
        return 1;
    }

    array = (int*)realloc(array, (n + m) * sizeof(int));
    if (array == NULL) {
        printf("Khong the cap phat lai bo nho\n");
        return 1;
    }

    for (int i = 0; i < m; i++) {
        printf("Nhap phan tu them thu %d: ", i + 1);
        scanf("%d", &array[n + i]);
    }

    printf("Mang sau khi them la: [ ");
    for (int i = 0; i < n + m; i++) {
        printf("%d", array[i]);
        if (i != n + m - 1) {
            printf(", ");
        }
    }
    printf(" ]\n");

    free(array);

    return 0;
}
