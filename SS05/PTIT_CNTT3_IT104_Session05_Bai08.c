#include <stdio.h>
#include <string.h>

int isDigit(char c) {
    return (c >= '0' && c <= '9');
}

int convertRecursive(char str[], int index, int length) {
    if (index == length)
        return 0;
    if (!isDigit(str[index]))
        return -1;

    int digit = str[index] - '0';
    int rest = convertRecursive(str, index + 1, length);

    if (rest == -1)
        return -1;

    return digit * pow10(length - index - 1) + rest;
}

int pow10(int n) {
    if (n == 0) return 1;
    return 10 * pow10(n - 1);
}

int main() {
    char input[100];
    int start = 0;
    int isNegative = 0;

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    int len = strlen(input);

    if (input[len - 1] == '\n') {
        input[len - 1] = '\0';
        len--;
    }

    if (input[0] == '-') {
        isNegative = 1;
        start = 1;
        if (len == 1) { 
            printf("Input khong hop le\n");
            return 0;
        }
    }

    int result = convertRecursive(input, start, len);

    if (result == -1) {
        printf("Input khong hop le\n");
    } else {
        if (isNegative)
            result = -result;
        printf("%d\n", result);
    }

    return 0;
}
