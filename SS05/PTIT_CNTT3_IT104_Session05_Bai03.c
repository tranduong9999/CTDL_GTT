#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1)
        return 1;
    return n * factorial(n - 1);
}

int stringToInt(char str[]) {
    int result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\n') {
        i++;
    }

    if (str[i] == '-') {
        return -1;
    }

    for (; str[i] != '\0' && str[i] != '\n'; i++) {
        if (str[i] < '0' || str[i] > '9') {
            return -1;
        }
        result = result * 10 + (str[i] - '0');
    }

    return result;
}

int main() {
    char input[100];
    int n;

    printf("Nhap mot so nguyen duong: ");
    fgets(input, sizeof(input), stdin);

    n = stringToInt(input);

    if (n <= 0) {
        printf("Khong hop le\n");
    } else {
        int result = factorial(n);
        printf("%d\n", result);
    }

    return 0;
}
