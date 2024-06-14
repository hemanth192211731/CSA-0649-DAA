#include <stdio.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int container_loader(int weights[], int values[], int capacity, int n) {
    int dp[n + 1][capacity + 1];

    for (int i = 0; i <= n; i++) {
        for (int j = 0; j <= capacity; j++) {
            if (i == 0 || j == 0) {
                dp[i][j] = 0;
            } else if (weights[i - 1] <= j) {
                dp[i][j] = max(values[i - 1] + dp[i - 1][j - weights[i - 1]], dp[i - 1][j]);
            } else {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][capacity];
}

int main() {
    int weights[] = {2, 3, 5, 7};
    int values[] = {10, 20, 30, 40};
    int capacity = 10;
    int n = sizeof(weights) / sizeof(weights[0]);

    printf("The optimal cost is: %d\n", container_loader(weights, values, capacity, n));

    return 0;
}