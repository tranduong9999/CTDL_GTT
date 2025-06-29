#include <stdio.h>

int fibonacci(int i) {
    if (i == 0) return 0;
    if (i == 1) return 1;
    return fibonacci(i - 1) + fibonacci(i - 2);
}

void printFibonacciReverse(int i) {
    if (i == 0) return;
    printf("%d", fibonacci(i - 1));
    if (i != 1) printf(", ");
    printFibonacciReverse(i - 1);
}

int main() {
    int n;

    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        printFibonacciReverse(n);
        printf("\n");
    }

    return 0;
}
