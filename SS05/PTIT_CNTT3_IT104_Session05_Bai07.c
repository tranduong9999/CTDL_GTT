#include <stdio.h>

int fibonacci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;

    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 1;
    }

    int result[n];

    for (int i = 0; i < n; i++) {
        result[i] = fibonacci(i);
    }

    printf("[");
    for (int i = 0; i < n; i++) {
        printf("%d", result[i]);
        if (i != n - 1)
            printf(",");
    }
    printf("]\n");

    return 0;
}
