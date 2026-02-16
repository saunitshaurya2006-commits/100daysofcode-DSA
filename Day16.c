//  Given an array of integers, count the frequency of each distinct element and print the result.

// Input:
// - First line: integer n (size of array)
// - Second line: n integers

// Output:
// - Print each element followed by its frequency in the format element:count

// Example:
// Input:
// 5
// 1 2 2 3 1

// Output:

#include <stdio.h>

int main() {
    int n, i, j, count;

    printf("Enter size: ");
    scanf("%d", &n);

    int arr[n];
    int visited[n];   // To mark counted elements

    // Initialize visited array to 0
    for(i = 0; i < n; i++) {
        visited[i] = 0;
    }

    printf("Enter elements: ");
    for(i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Count frequency
    for(i = 0; i < n; i++) {

        if(visited[i] == 1)
            continue;

        count = 1;

        for(j = i + 1; j < n; j++) {
            if(arr[i] == arr[j]) {
                count++;
                visited[j] = 1;
            }
        }

        printf("%d:%d\n", arr[i], count);
    }

    return 0;
}
