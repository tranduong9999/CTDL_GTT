#include <stdio.h>

void printNumbers(int n) {
    if (n == 0) {
        return
    }
    printNumbers(n - 1);
    printf("%d ", n);
}

int main() {
    int n;

    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Vui long nhap so nguyen duong lon hon 0.\n");
    } else {
        printf("Cac so tu 1 den %d la:\n", n);
        printNumbers(n);
        printf("\n");
    }

    return 0;
}

