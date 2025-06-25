#include <stdio.h>

int main() {
    int n;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int array[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    int min = array[0];
    int index = 0;

    for (int i = 1; i < n; i++) {
        if (array[i] < min) {
            min = array[i];
            index = i;
        }
    }

    printf("%d\n", index);

    return 0;
}
