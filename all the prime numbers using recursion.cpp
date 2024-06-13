#include <stdio.h>

int is_prime(int n, int i) {
    if (i == 1)
        return 1;
    else if (n <= 2)
        return (n == 2) ? 1 : 0;
    else if (n % i == 0)
        return 0;
    else
        return is_prime(n, i - 1);
}

void generate_primes(int n) {
    for (int i = 2; i <= n; i++) {
        if (is_prime(i, i / 2))
            printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter a number: ");
    scanf("%d", &n);
    generate_primes(n);
    return 0;
}