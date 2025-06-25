#include <stdio.h>

int main() {
    int n;
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

    for (int i = 0; i < n / 2; i++) {
        if (array[i] == array[n - 1 - i]) {
            printf("Cap doi xung: (%d, %d)\n", array[i], array[n - 1 - i]);
            found = 1;
        }
    }

    if (!found) {
        printf("Khong co phan tu doi xung\n");
    }

    return 0;
}
