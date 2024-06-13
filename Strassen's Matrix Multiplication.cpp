#include <stdio.h>

void strassen_matrix_multiply(int A[2][2], int B[2][2], int C[2][2]) {
    int M1 = A[0][0] * (B[1][1] - B[1][0]) + A[0][1] * B[1][0];
    int M2 = (A[0][0] + A[0][1]) * B[1][1];
    int M3 = (A[1][0] + A[1][1]) * B[0][0];
    int M4 = A[1][1] * (B[0][1] - B[0][0]);
    int M5 = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
    int M6 = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);
    int M7 = (A[0][0] - A[1][0]) * (B[0][0] + B[0][1]);

    C[0][0] = M5 + M4 - M2 + M6;
    C[0][1] = M1 + M2;
    C[1][0] = M3 + M4;
    C[1][1] = M5 + M1 - M3 - M7;
}

int main() {
    int A[2][2], B[2][2], C[2][2];
    printf("Enter matrix A:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &A[i][j]);
    printf("Enter matrix B:\n");
    for (int i = 0; i < 2; i++)
        for (int j = 0; j < 2; j++)
            scanf("%d", &B[i][j]);
    strassen_matrix_multiply(A, B, C);
    printf("Resultant matrix C:\n");
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 2; j++)
            printf("%d ", C[i][j]);
        printf("\n");
    }
    return 0;
}