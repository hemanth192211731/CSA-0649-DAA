#include <stdio.h>

int find_largest(int arr[], int n) {
    if (n == 1)
        return arr[0];
    int max = find_largest(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}

int main() {
    int arr[100];
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Largest element is %d.\n", find_largest(arr, n));
    return 0;
}  