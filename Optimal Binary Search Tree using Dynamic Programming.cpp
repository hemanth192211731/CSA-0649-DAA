#include <stdio.h>
#include <limits.h>

#define MAX 100

int cost[MAX][MAX];

int optimalBST(int keys[], int freq[], int n) {
    int i, j, k;
    for (i = 0; i < n; i++)
        cost[i][i] = freq[i];

    for (j = 1; j < n; j++) {
        for (i = 0; i < n - j; i++) {
            k = i + j;
            cost[i][k] = INT_MAX;
            for (int r = i; r <= k; r++) {
                int c = (r == i)? 0 : cost[i][r - 1];
                c += (r == k)? 0 : cost[r + 1][k];
                c += freq[r];
                for (int l = i; l <= k; l++)
                    c += freq[l];
                if (c < cost[i][k])
                    cost[i][k] = c;
            }
        }
    }

    return cost[0][n - 1];
}

int main() {
    int keys[] = {10, 20, 30, 40};
    int freq[] = {4, 2, 6, 3};
    int n = sizeof(keys) / sizeof(keys[0]);
    printf("Optimal BST cost = %d\n", optimalBST(keys, freq, n));
    return 0;
}