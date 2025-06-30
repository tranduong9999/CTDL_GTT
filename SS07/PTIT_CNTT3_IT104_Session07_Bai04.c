#include <stdio.h>
#include <string.h>
#include <ctype.h>

void sortString(char str[]) {
    int len = strlen(str);
    for (int i = 0; i < len - 1; i++) {
        for (int j = i + 1; j < len; j++) {
            if (str[i] > str[j]) {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }
}

int main() {
    char str[1000];

    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);

    str[strcspn(str, "\n")] = '\0';

    int isValid = 0;
    for (int i = 0; str[i]; i++) {
        if (!isspace((unsigned char)str[i])) {
            isValid = 1;
            break;
        }
    }

    if (!isValid) {
        printf("Chuoi khong hop le\n");
        return 0;
    }

    printf("Truoc sap xep: \"%s\"\n", str);

    sortString(str);

    printf("Sau sap xep: \"%s\"\n", str);

    return 0;
}
