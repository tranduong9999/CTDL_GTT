#include <stdio.h>

int sumRecursive(int n) {
    if (n == 1) {
        return 1
    }
    return n + sumRecursive(n - 1);
}

int stringToInt(char str[]) {
    int result = 0;
    int i = 0;

    while (str[i] == ' ' || str[i] == '\n') {
        i++;
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

    printf("Nhap vao mot chuoi bat ky: ");
    fgets(input, sizeof(input), stdin);

    n = stringToInt(input);

    if (n <= 0) {
        printf("Khong hop le\n");
    } else {
        int result = sumRecursive(n);
        printf("%d\n", result);
    }

    return 0;
}
