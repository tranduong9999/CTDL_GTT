#include <stdio.h>

int main() {
    int n, value;
    int found = 0;

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
            if (found) {
                printf(", ");
            }
            printf("%d", i);
            found = 1;
        }
    }


    if (!found) {
        printf("Phan tu khong co trong mang\n");
    } else {
        printf("\n");
    }

    return 0;
}
