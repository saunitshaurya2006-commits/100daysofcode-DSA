// Perform BFS from a given source using queue.

// Input:
// - n
// - adjacency list
// - source s

// Output:
// - BFS traversal order

#include <stdio.h>
#define MAX 100

int queue[MAX], front = -1, rear = -1;
int visited[MAX];

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1) return;
    if (front == -1) front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear) return -1;
    return queue[front++];
}

// BFS function
void bfs(int n, int adj[MAX][MAX], int s) {
    enqueue(s);
    visited[s] = 1;

    while (front <= rear) {
        int u = dequeue();
        printf("%d ", u);

        for (int v = 0; v < n; v++) {
            if (adj[u][v] == 1 && !visited[v]) {
                enqueue(v);
                visited[v] = 1;
            }
        }
    }
}

int main() {
    int n, s;
    int adj[MAX][MAX];

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    printf("Enter adjacency matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    printf("Enter source vertex: ");
    scanf("%d", &s);

    // Initialize visited array
    for (int i = 0; i < n; i++)
        visited[i] = 0;

    printf("BFS Traversal: ");
    bfs(n, adj, s);

    return 0;
}
