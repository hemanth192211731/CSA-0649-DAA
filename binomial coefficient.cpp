#include <stdio.h>

#define MAX 100

int binomialCoeff(int n, int k) {
    int C[MAX][MAX];
    int i, j;

    // Initialize the first row and column to 1
    for (i = 0; i <= n; i++) {
        C[i][0] = 1;
        C[i][i] = 1;
    }

    // Fill in the rest of the table using dynamic programming
    for (i = 2; i <= n; i++) {
        for (j = 1; j < i; j++) {
            C[i][j] = C[i-1][j-1] + C[i-1][j];
        }
    }

    return C[n][k];
}

int main() {
    int n, k;
    printf("Enter the value of n: ");
    scanf("%d", &n);
    printf("Enter the value of k: ");
    scanf("%d", &k);

    int result = binomialCoeff(n, k);
    printf("Binomial coefficient (%d choose %d) = %d\n", n, k, result);

    return 0;
}