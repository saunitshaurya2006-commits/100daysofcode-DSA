// Given weighted undirected graph, compute total weight of Minimum Spanning Tree using Prim’s algorithm.

// Input Format
// n m
// u v w
// ...

// Output Format
// Total weight of MST.

// Sample Input
// 4 5
// 1 2 3
// 1 3 5
// 2 3 1
// 2 4 4
// 3 4 2

// Sample Output
// 6

// Explanation
// One possible MST edges: (2-3), (3-4), (1-2)

#include <stdio.h>
#include <limits.h>

#define MAX 100

int graph[MAX][MAX];
int visited[MAX];
int key[MAX];

int findMinVertex(int n) {
    int min = INT_MAX, vertex = -1;

    for (int i = 1; i <= n; i++) {
        if (!visited[i] && key[i] < min) {
            min = key[i];
            vertex = i;
        }
    }
    return vertex;
}

int primMST(int n) {
    for (int i = 1; i <= n; i++) {
        key[i] = INT_MAX;
        visited[i] = 0;
    }

    key[1] = 0;
    int totalWeight = 0;

    for (int count = 1; count <= n; count++) {
        int u = findMinVertex(n);
        visited[u] = 1;
        totalWeight += key[u];

        for (int v = 1; v <= n; v++) {
            if (graph[u][v] != 0 && !visited[v] && graph[u][v] < key[v]) {
                key[v] = graph[u][v];
            }
        }
    }

    return totalWeight;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            graph[i][j] = 0;
        }
    }

    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        graph[u][v] = w;
        graph[v][u] = w;
    }

    printf("%d\n", primMST(n));

    return 0;
}
