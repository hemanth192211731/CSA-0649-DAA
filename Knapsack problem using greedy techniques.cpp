#include <stdio.h>

typedef struct {
    int value;
    int weight;
} Item;

void knapsack(Item items[], int n, int capacity) {
    int i, w = 0;
    float ratio[n], max_ratio;

    for (i = 0; i < n; i++) {
        ratio[i] = (float)items[i].value / items[i].weight;
    }

    for (i = 0; i < n - 1; i++) {
        int max_index = i;
        for (int j = i + 1; j < n; j++) {
            if (ratio[j] > ratio[max_index])
                max_index = j;
        }
        Item temp = items[i];
        items[i] = items[max_index];
        items[max_index] = temp;
    }

    for (i = 0; i < n; i++) {
        if (w + items[i].weight <= capacity) {
            w += items[i].weight;
            printf("Item %d is included in the knapsack\n", i + 1);
        } else {
            int remaining_weight = capacity - w;
            printf("Item %d is included in the knapsack with weight %d\n", i + 1, remaining_weight);
            break;
        }
    }
}

int main() {
    int n, capacity;
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the capacity of the knapsack: ");
    scanf("%d", &capacity);

    Item items[n];
    printf("Enter the value and weight of each item:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &items[i].value, &items[i].weight);
    }

    knapsack(items, n, capacity);

    return 0;
}