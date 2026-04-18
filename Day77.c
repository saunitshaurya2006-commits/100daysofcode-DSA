// Using BFS or DFS, check if the entire graph is connected.

// Input Format
// n m
// edges

// Output Format
// CONNECTED
// NOT CONNECTED

// Sample Input
// 4 2
// 1 2
// 3 4

// Sample Output
// NOT CONNECTED

#include <stdio.h>

#define MAX 100

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

    dfs(1);

    int connected = 1;

    for (int i = 1; i <= n; i++)
    {
        if (visited[i] == 0)
        {
            connected = 0;
            break;
        }
    }

    if (connected)
    {
        printf("CONNECTED\n");
    }
    else
    {
        printf("NOT CONNECTED\n");
    }

    return 0;
}
