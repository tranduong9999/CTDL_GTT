#include <stdio.h>

void printBinary(int n) {
    if (n == 0)
        return;
    printBinary(n / 2);             // đệ quy phần nguyên
    printf("%d", n % 2);            // in phần dư (bit)
}

int main() {
    int n;

    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
    } else {
        printBinary(n);
        printf("\n");
    }

    return 0;
}
