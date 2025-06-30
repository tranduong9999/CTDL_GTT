#include <stdio.h>

void printArray(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d", arr[i]);
        if (i < n - 1) printf(", ");
    }
    printf(" ]\n");
}

int main() {
    int n;
    int arr[1000];

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before sort: ");
    printArray(arr, n);

    int negative[1000], zero[1000], positive[1000];
    int negCount = 0, zeroCount = 0, posCount = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] < 0)
            negative[negCount++] = arr[i];
        else if (arr[i] == 0)
            zero[zeroCount++] = arr[i];
        else
            positive[posCount++] = arr[i];
    }

    int index = 0;
    for (int i = 0; i < negCount; i++)
        arr[index++] = negative[i];
    for (int i = 0; i < zeroCount; i++)
        arr[index++] = zero[i];
    for (int i = 0; i < posCount; i++)
        arr[index++] = positive[i];

    printf("After sort: ");
    printArray(arr, n);

    return 0;
}
