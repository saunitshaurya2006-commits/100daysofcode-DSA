// Find shortest distances from source vertex in a weighted graph with non-negative weights.

// Input Format
// n m
// u v w
// source

// Output Format
// Distances to all vertices.

// Sample Input
// 5 6
// 1 2 2
// 1 3 4
// 2 3 1
// 2 4 7
// 3 5 3
// 4 5 1
// 1

// Sample Output
// 0 2 3 9 6

// Explanation
// Shortest distances computed via priority queue.

#include <stdio.h>
#include <stdlib.h>

#define MAX 100
#define INF 999999

int main()
{
    int n, m;
    int graph[MAX][MAX];
    int dist[MAX];
    int visited[MAX];

    // Initialize graph with INF
    for (int i = 0; i < MAX; i++)
    {
        for (int j = 0; j < MAX; j++)
        {
            graph[i][j] = INF;
        }
    }

    // Input number of vertices and edges
    scanf("%d %d", &n, &m);

    // Input edges
    for (int i = 0; i < m; i++)
    {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);

        u--; // Convert to 0-based index
        v--;

        graph[u][v] = w;
        graph[v][u] = w; // Remove this line for directed graph
    }

    int source;
    scanf("%d", &source);
    source--;

    // Initialize distances and visited array
    for (int i = 0; i < n; i++)
    {
        dist[i] = INF;
        visited[i] = 0;
    }

    dist[source] = 0;

    // Dijkstra's Algorithm
    for (int count = 0; count < n - 1; count++)
    {
        int min = INF, u = -1;

        // Find unvisited vertex with minimum distance
        for (int i = 0; i < n; i++)
        {
            if (!visited[i] && dist[i] < min)
            {
                min = dist[i];
                u = i;
            }
        }

        if (u == -1)
            break;

        visited[u] = 1;

        // Update distances of adjacent vertices
        for (int v = 0; v < n; v++)
        {
            if (!visited[v] &&
                graph[u][v] != INF &&
                dist[u] + graph[u][v] < dist[v])
            {
                dist[v] = dist[u] + graph[u][v];
            }
        }
    }

    // Print shortest distances
    for (int i = 0; i < n; i++)
    {
        printf("%d ", dist[i]);
    }

    return 0;
}
