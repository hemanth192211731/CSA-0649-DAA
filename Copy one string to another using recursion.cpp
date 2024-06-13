#include <stdio.h>

void copy_string(char str1[], char str2[], int i) {
    if (str1[i] == '\0') {
        str2[i] = '\0';
        return;
    }
    str2[i] = str1[i];
    copy_string(str1, str2, i + 1);
}

int main() {
    char str1[100], str2[100];
    printf("Enter a string: ");
    scanf("%s", str1);
    copy_string(str1, str2, 0);
    printf("Copied string: %s\n", str2);
    return 0;
}