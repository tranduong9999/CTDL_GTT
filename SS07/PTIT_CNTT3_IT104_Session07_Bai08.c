#include <stdio.h>
void printMatrix(int a[][1000], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int rows, cols, k;
    int a[1000][1000];

    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    if (rows <= 0 || rows >= 1000 || cols <= 0 || cols >= 1000) {
        printf("So cot va so hang khong hop le\n");
        return 1;
    }

    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            scanf("%d", &a[i][j]);
        }
    }

    printf("Nhap chi so cot k can sap xep: ");
    scanf("%d", &k);

    if (k < 0 || k >= cols) {
        printf("Chi so cot khong hop le\n");
        return 1;
    }

    for (int i = 0; i < rows - 1; i++) {
        for (int j = i + 1; j < rows; j++) {
            if (a[i][k] > a[j][k]) {
                for (int col = 0; col < cols; col++) {
                    int temp = a[i][col];
                    a[i][col] = a[j][col];
                    a[j][col] = temp;
                }
            }
        }
    }

    printf("Ma tran sau khi sap xep cot %d:\n", k);
    printMatrix(a, rows, cols);

    return 0;
}
