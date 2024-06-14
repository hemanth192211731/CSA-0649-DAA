#include <stdio.h>

void factors(int n, int i) {
    if (i > n) {
        return;
    }
    if (n % i == 0) {
        printf("%d ", i);
    }
    factors(n, i + 1);
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);

    printf("The factors of %d are: ", n);
    factors(n, 1);
    printf("\n");

    return 0;
}