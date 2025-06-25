#include <stdio.h>

int main() {
    int n, value, found = 0;

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

    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    for (int i = 0; i < n; i++) {
        if (array[i] == value) {
            printf("%d\n", i);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay phan tu\n");
    }

    return 0;
}
