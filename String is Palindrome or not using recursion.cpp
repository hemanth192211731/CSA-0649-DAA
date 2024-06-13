#include <stdio.h>
#include <string.h>

int is_palindrome(char str[], int start, int end) {
    if (start >= end)
        return 1;
    if (str[start] != str[end])
        return 0;
    return is_palindrome(str, start + 1, end - 1);
}
int main() {
    char str[100];
    printf("Enter a string: ");
    scanf("%s", str);
    int n = strlen(str);
    if (is_palindrome(str, 0, n - 1))
        printf("%s is a palindrome.\n", str);
    else
        printf("%s is not a palindrome.\n", str);
    return 0;
}