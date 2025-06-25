#include <stdio.h>
#include <stdlib.h>

float tinhTrungBinhChan(int *array, int n) {
    int tong = 0, dem = 0;
    for (int i = 0; i < n; i++) {
        if (array[i] % 2 == 0) {
            tong += array[i];
            dem++;
        }
    }

    if (dem == 0) {
        return 0;
    }

    return (float)tong / dem;
}

int main() {
    int n;
    int *array;

    printf("Nhap so luong phan tu: ");
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

    float average = tinhTrungBinhChan(array, n);
    printf("average = %.2f\n", average);

    free(array);

    return 0;
}
