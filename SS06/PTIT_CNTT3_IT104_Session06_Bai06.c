#include <stdio.h>

int countWays(int n) {
    if (n == 1)
        return 1;
    if (n == 2)
        return 2;
    return countWays(n - 1) + countWays(n - 2);
}

int main() {
    int n;
    printf("Nhap so bac cau thang: ");
    scanf("%d", &n);

    if (n <= 0) {
        printf("Input khong hop le\n");
        return 1;
    }

    int result = countWays(n);
    printf("%d\n", result);

    return 0;
}
