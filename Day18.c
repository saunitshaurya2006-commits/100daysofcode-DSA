// Given an array of integers, rotate the array to the right by k positions.

// Input:
// - First line: integer n
// - Second line: n integers
// - Third line: integer k

// Output:
// - Print the rotated array

// Example:
// Input:
// 5
// 1 2 3 4 5
// 2

// Output:
// 4 5 1 2 3

#include <stdio.h>

int main() {
    int n, k;
    
    // Input size
    scanf("%d", &n);
    
    int arr[n];
    
    // Input array elements
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    // Input k
    scanf("%d", &k);
    
    // Handle k greater than n
    k = k % n;
    
    // Rotate and print
    for(int i = n - k; i < n; i++) {
        printf("%d ", arr[i]);
    }
    
    for(int i = 0; i < n - k; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}
