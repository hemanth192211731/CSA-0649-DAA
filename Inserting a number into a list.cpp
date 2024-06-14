#include <stdio.h>

void insert_number(int lst[], int num, int *size) {
    lst[(*size)++] = num;
}

int main() {
    int lst[10];
    int size = 0;

    insert_number(lst, 1, &size);
    insert_number(lst, 2, &size);
    insert_number(lst, 3, &size);
    insert_number(lst, 4, &size);
    insert_number(lst, 5, &size);

    printf("The list is: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", lst[i]);
    }
    printf("\n");

    return 0;
}