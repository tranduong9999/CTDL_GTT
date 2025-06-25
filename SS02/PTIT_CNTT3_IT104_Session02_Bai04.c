#include <stdio.h>
#include <stdlib.h>

int tinhTongCheoChinh(int **arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][i];
    }
    return sum;
}

int tinhTongCheoPhu(int **arr, int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i][n - 1 - i];
    }
    return sum;
}

int main() {
    int rows, cols;

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
        return 1;
    } else if (rows <= 0) {
        printf("So hang khong hop le\n");
        return 1;
    } else if (cols <= 0) {
        printf("So cot khong hop le\n");
        return 1;
    }

    int **array = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        array[i] = (int*)malloc(cols * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }

    if (rows == cols) {
        int tongChinh = tinhTongCheoChinh(array, rows);
        int tongPhu = tinhTongCheoPhu(array, rows);
        printf("Tong duong cheo chinh = %d\n", tongChinh);
        printf("Tong duong cheo phu = %d\n", tongPhu);
    } else {
        printf("Khong ton tai duong cheo chinh\n");
        printf("Khong ton tai duong cheo phu\n");
    }

    for (int i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}
