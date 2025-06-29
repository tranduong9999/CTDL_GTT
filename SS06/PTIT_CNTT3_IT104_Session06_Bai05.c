#include <stdio.h>

int findMax(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int maxRest = findMax(arr, n - 1);
    return (arr[n - 1] > maxRest) ? arr[n - 1] : maxRest;
}

int findMin(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int minRest = findMin(arr, n - 1);
    return (arr[n - 1] < minRest) ? arr[n - 1] : minRest;
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("Input khong hop le\n");
        return 1;
    }

    int arr[n];
    for (int i = 0; i < n; i++) {
        printf("Nhap arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    int min = findMin(arr, n);
    int max = findMax(arr, n);

    printf("%d, %d\n", min, max);

    return 0;
}
