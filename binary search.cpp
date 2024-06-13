#include <stdio.h>

int binary_search(int arr[], int target, int low, int high) {
    if (low > high)
        return -1;
    int mid = (low + high) / 2;
    if (arr[mid] == target)
        return mid;
    else if (arr[mid] < target)
        return binary_search(arr, target, mid + 1, high);
    else
        return binary_search(arr, target, low, mid - 1);
}

int main() {
    int arr[100], n, target;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    printf("Enter the elements in sorted order: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);
    printf("Enter the target element: ");
    scanf("%d", &target);
    int result = binary_search(arr, target, 0, n - 1);
    if (result != -1)
        printf("Element found at index %d.\n", result);
    else
        printf("Element not found.\n");
    return 0;
}