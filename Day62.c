// Build a graph with adjacency list representation. Use linked lists or dynamic arrays.

// Input:
// - n (vertices)
// - m (edges)
// - edges (u, v)

// Output:
// - List of adjacency lists for each vertex

#include <stdio.h>
#include <stdlib.h>

// Graph structure
typedef struct {
    int *data;     // dynamic array to store neighbors
    int size;      // current number of neighbors
    int capacity;  // capacity of array
} List;

// Initialize list
void initList(List *list) {
    list->size = 0;
    list->capacity = 2;
    list->data = (int*)malloc(list->capacity * sizeof(int));
}

// Add element to list
void addToList(List *list, int value) {
    if (list->size == list->capacity) {
        list->capacity *= 2;
        list->data = (int*)realloc(list->data, list->capacity * sizeof(int));
    }
    list->data[list->size++] = value;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // Create adjacency list
    List *adj = (List*)malloc(n * sizeof(List));

    for (int i = 0; i < n; i++) {
        initList(&adj[i]);
    }

    // Input edges
    int u, v;
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &u, &v);

        // Undirected graph
        addToList(&adj[u], v);
        addToList(&adj[v], u);
    }

    // Print adjacency list
    for (int i = 0; i < n; i++) {
        printf("Vertex %d: ", i);
        for (int j = 0; j < adj[i].size; j++) {
            printf("%d -> ", adj[i].data[j]);
        }
        printf("NULL\n");
    }

    return 0;
}
