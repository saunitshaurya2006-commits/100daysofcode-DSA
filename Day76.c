// Using DFS or BFS, count number of connected components.

// Input Format
// n m
// edges

// Output Format
// Number of connected components.

// Sample Input
// 6 3
// 1 2
// 2 3
// 5 6

// Sample Output
// 3

// Explanation
// Components: {1,2,3}, {4}, {5,6}

#include <stdio.h>

#define MAX 1000

int graph[MAX][MAX];
int visited[MAX];
int n, m;

void dfs(int node)
{
    visited[node] = 1;

    for (int i = 1; i <= n; i++)
    {
        if (graph[node][i] == 1 && visited[i] == 0)
        {
            dfs(i);
        }
    }
}

int main()
{
    scanf("%d %d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int u, v;
        scanf("%d %d", &u, &v);

        graph[u][v] = 1;
        graph[v][u] = 1;
    }

    int connectedComponents = 0;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            connectedComponents++;
            dfs(i);
        }
    }

    printf("%d\n", connectedComponents);

    return 0;
}
