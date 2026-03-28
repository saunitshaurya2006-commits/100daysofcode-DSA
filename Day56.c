// Check whether a given binary tree is symmetric around its center.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal (-1 indicates NULL)

// Output Format:
// - Print YES if symmetric, otherwise NO

// Example:
// Input:
// 7
// 1 2 2 3 4 4 3

// Output:
// YES

// Explanation:
// Left subtree is a mirror image of the right subtree.

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int val;
    struct Node *left, *right;
} Node;

// Queue structure for building tree from level-order
typedef struct {
    Node **arr;
    int front, rear;
} Queue;

Queue* createQueue(int size) {
    Queue *q = (Queue*)malloc(sizeof(Queue));
    q->arr = (Node**)malloc(sizeof(Node*) * size);
    q->front = q->rear = 0;
    return q;
}

void enqueue(Queue *q, Node *node) {
    q->arr[q->rear++] = node;
}

Node* dequeue(Queue *q) {
    return q->arr[q->front++];
}

int isEmpty(Queue *q) {
    return q->front == q->rear;
}

Node* newNode(int val) {
    if (val == -1) return NULL;
    Node *node = (Node*)malloc(sizeof(Node));
    node->val = val;
    node->left = node->right = NULL;
    return node;
}

// Mirror check
int isMirror(Node *t1, Node *t2) {
    if (!t1 && !t2) return 1;
    if (!t1 || !t2) return 0;
    return (t1->val == t2->val) &&
           isMirror(t1->left, t2->right) &&
           isMirror(t1->right, t2->left);
}

int isSymmetric(Node *root) {
    if (!root) return 1;
    return isMirror(root->left, root->right);
}

int main() {
    int N;
    scanf("%d", &N);
    int arr[N];
    for (int i = 0; i < N; i++) scanf("%d", &arr[i]);

    if (N == 0) {
        printf("YES\n");
        return 0;
    }

    Node *root = newNode(arr[0]);
    Queue *q = createQueue(N);
    enqueue(q, root);

    int i = 1;
    while (!isEmpty(q) && i < N) {
        Node *curr = dequeue(q);
        if (curr) {
            curr->left = newNode(arr[i++]);
            if (curr->left) enqueue(q, curr->left);
            if (i < N) {
                curr->right = newNode(arr[i++]);
                if (curr->right) enqueue(q, curr->right);
            }
        }
    }

    if (isSymmetric(root)) printf("YES\n");
    else printf("NO\n");

    return 0;
}
