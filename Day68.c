// Implement topological sorting using in-degree array and queue (Kahnâ€™s Algorithm).

#include <stdio.h>
#include <stdlib.h>

#define MAX 100

int queue[MAX], front = -1, rear = -1;

// Queue operations
void enqueue(int x) {
    if (rear == MAX - 1)
        return;
    if (front == -1)
        front = 0;
    queue[++rear] = x;
}

int dequeue() {
    if (front == -1 || front > rear)
        return -1;
    return queue[front++];
}

int isEmpty() {
    return (front == -1 || front > rear);
}

int main() {
    int n, i, j;

    printf("Enter number of vertices: ");
    scanf("%d", &n);

    int adj[MAX][MAX], indegree[MAX] = {0};

    printf("Enter adjacency matrix:\n");
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &adj[i][j]);
        }
    }

    // Calculate in-degree
    for(i = 0; i < n; i++) {
        for(j = 0; j < n; j++) {
            if(adj[i][j] == 1)
                indegree[j]++;
        }
    }

    // Enqueue vertices with in-degree 0
    for(i = 0; i < n; i++) {
        if(indegree[i] == 0)
            enqueue(i);
    }

    printf("Topological Order: ");
    int count = 0;

    while(!isEmpty()) {
        int u = dequeue();
        printf("%d ", u);
        count++;

        for(i = 0; i < n; i++) {
            if(adj[u][i] == 1) {
                indegree[i]--;
                if(indegree[i] == 0)
                    enqueue(i);
            }
        }
    }

    // Check for cycle
    if(count != n)
        printf("\nCycle detected! Topological sort not possible.\n");

    return 0;
}
