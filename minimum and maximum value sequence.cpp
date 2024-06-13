#include <stdio.h>

void find_min_max(int arr[], int n, int *min, int *max) {
    *min = *max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < *min)
            *min = arr[i];
        else if (arr[i] > *max)
            *max = arr[i];
    }
}

int main() {
    int arr[100], n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    int min, max;
    find_min_max(arr, n, &min, &max);
    printf("Minimum value: %d\n", min);
    printf("Maximum value: %d\n", max);
    return 0;
}