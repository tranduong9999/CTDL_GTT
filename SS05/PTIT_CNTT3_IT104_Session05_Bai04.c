#include <stdio.h>

int sumRecursive(int a, int b) {
    if (a == b)
        return a;
    return a + sumRecursive(a + 1, b);
}

int main() {
    int firstNum, secondNum;

    printf("Nhap firstNum: ");
    scanf("%d", &firstNum);

    printf("Nhap secondNum: ");
    scanf("%d", &secondNum);

    if (firstNum <= 0 || secondNum <= 0 || firstNum > secondNum) {
        printf("Khong hop le\n");
    } else {
        int result = sumRecursive(firstNum, secondNum);
        printf("%d\n", result);
    }

    return 0;
}
