#include <stdio.h>
#include <stdlib.h>

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int *arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
            }
        }
    }
}

int binarySearch(int *arr, int n, int target) {
    int left = 0, right = n - 1;

    while (left <= right) {
        int mid = (left + right) / 2;

        if (arr[mid] == target)
            return 1; // Tìm thấy
        else if (arr[mid] < target)
            left = mid + 1;
        else
            right = mid - 1;
    }

    return 0;
}

int main() {
    int n, value;

    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le\n");
        return 1;
    }

    int array[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &array[i]);
    }

    bubbleSort(array, n);

    printf("Nhap gia tri can tim: ");
    scanf("%d", &value);

    if (binarySearch(array, n, value)) {
        printf("Phan tu co trong mang\n");
    } else {
        printf("Phan tu khong co trong mang\n");
    }

    return 0;
}
