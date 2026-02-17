// Write a program to find the maximum and minimum values present in a given array of integers.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the maximum and minimum elements

// Example:
// Input:
// 6
// 3 5 1 9 2 8

// Output:
// Max: 9
// Min: 1

#include <stdio.h>

int main() {
    int n, i;

    // Read size of array
    scanf("%d", &n);

    int arr[n];

    // Read array elements
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Assume first element as max and min
    int max = arr[0];
    int min = arr[0];

    // Find max and min
    for(i = 1; i < n; i++) {
        if(arr[i] > max) {
            max = arr[i];
        }
        if(arr[i] < min) {
            min = arr[i];
        }
    }

    // Print result
    printf("Max: %d\n", max);
    printf("Min: %d\n", min);

    return 0;
}
