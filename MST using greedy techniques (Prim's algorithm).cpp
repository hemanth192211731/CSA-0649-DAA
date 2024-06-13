#include <stdio.h>
#include <limits.h>

#define V 5

void primMST(int graph[V][V]) {
    int key[V], parent[V], visited[V];
    int i, j, min, min_index;

    for (i = 0; i < V; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[0] = 0;
    parent[0] = -1;

    for (i = 0; i < V - 1; i++) {
        min = INT_MAX;
        for (j = 0; j < V; j++) {
            if (visited[j] == 0 && key[j] < min) {
                min = key[j];
                min_index = j;
            }
        }

        visited[min_index] = 1;

        for (j = 0; j < V; j++) {
            if (graph[min_index][j] && visited[j] == 0 && graph[min_index][j] < key[j]) {
                parent[j] = min_index;
                key[j] = graph[min_index][j];
            }
        }
    }

    printf("Edge \tWeight\n");
    for (i = 1; i < V; i++)
        printf("%d - %d \t%d\n", parent[i], i, graph[i][parent[i]]);
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6, 0},
        {2, 0, 3, 8, 5},
        {0, 3, 0, 0, 7},
        {6, 8, 0, 0, 9},
        {0, 5, 7, 9, 0}
    };

    primMST(graph);

    return 0;
}