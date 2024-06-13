#include <stdio.h>
#include <time.h>

void multiply_matrices(int mat1[][100], int mat2[][100], int res[][100], int r1, int c1, int r2, int c2) {
    int i, j, k;
    for (i = 0; i < r1; i++) {
        for (j = 0; j < c2; j++) {
            res[i][j] = 0;
            for (k = 0; k < c1; k++)
                res[i][j] += mat1[i][k] * mat2[k][j];
        }
    }
}

int main() {
    int r1, c1, r2, c2;
    printf("Enter the number of rows and columns for matrix 1: ");
    scanf("%d %d", &r1, &c1);
    printf("Enter the number of rows and columns for matrix 2: ");
    scanf("%d %d", &r2, &c2);
    if (c1 != r2) {
        printf("Matrices cannot be multiplied.\n");
        return 0;
    }
    int mat1[100][100], mat2[100][100], res[100][100];
    printf("Enter elements of matrix 1: ");
    for (int i = 0; i < r1; i++)
        for (int j = 0; j < c1; j++)
            scanf("%d", &mat1[i][j]);
    printf("Enter elements of matrix 2: ");
    for (int i = 0; i < r2; i++)
        for (int j = 0; j < c2; j++)
            scanf("%d", &mat2[i][j]);
    clock_t start = clock();
    multiply_matrices(mat1, mat2, res, r1, c1, r2, c2);
    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC;
    printf("Time taken to multiply matrices: %f seconds.\n", time_taken);
    return 0;
}