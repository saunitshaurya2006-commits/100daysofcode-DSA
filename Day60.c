// Check whether a given binary tree satisfies the Min-Heap property.

// Input Format:
// - First line contains integer N
// - Second line contains level-order traversal

// Output Format:
// - Print YES if valid Min-Heap, otherwise NO

// Example:
// Input:
// 7
// 1 3 5 7 9 8 10

// Output:
// YES

// Explanation:
// Each parent node must be smaller than its children.

#include <stdio.h>

int isMinHeap(int arr[], int n) {
    int i;

    // Check all parent nodes
    for (i = 0; i <= (n - 2) / 2; i++) {
        int left = 2 * i + 1;
        int right = 2 * i + 2;

        // Check left child
        if (arr[i] > arr[left])
            return 0;

        // Check right child (if exists)
        if (right < n && arr[i] > arr[right])
            return 0;
    }

    return 1;
}

int main() {
    int n, i;

    // Input number of nodes
    scanf("%d", &n);

    int arr[n];

    // Input level order traversal
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Check Min-Heap
    if (isMinHeap(arr, n)) {
        printf("YES\n");
    } else {
        printf("NO\n");
    }

    return 0;
}
