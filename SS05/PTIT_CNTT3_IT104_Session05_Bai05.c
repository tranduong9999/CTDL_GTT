#include <stdio.h>
#include <string.h>
#include <ctype.h>

int isPalindrome(char str[], int left, int right) {
    if (left >= right)
        return 1;
    if (str[left] != str[right])
        return 0;
    return isPalindrome(str, left + 1, right - 1);
}

void cleanString(char src[], char dest[]) {
    int j = 0;
    for (int i = 0; src[i] != '\0'; i++) {
        if (isalnum(src[i])) {
            dest[j++] = tolower(src[i]);
        }
    }
    dest[j] = '\0';
}

int main() {
    char input[1000];
    char cleaned[1000];

    printf("Nhap chuoi: ");
    fgets(input, sizeof(input), stdin);

    cleanString(input, cleaned);

    int length = strlen(cleaned);
    if (length == 0) {
        printf("Palindrome invalid\n");
        return 0;
    }

    if (isPalindrome(cleaned, 0, length - 1)) {
        printf("Palindrome valid\n");
    } else {
        printf("Palindrome invalid\n");
    }

    return 0;
}
