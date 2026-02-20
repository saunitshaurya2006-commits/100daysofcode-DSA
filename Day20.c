// Given an array of integers, count the number of subarrays whose sum is equal to zero.

// Input:
// - First line: integer n
// - Second line: n integers

// Output:
// - Print the count of subarrays having sum zero

// Example:
// Input:
// 6
// 1 -1 2 -2 3 -3

// Output:
// 6

// Explanation: A subarray is a continuous part of the array. For the input array 1 -1 2 -2 3 -3, the following subarrays have sum zero: [1, -1], [2, -2], [3, -3], [1, -1, 2, -2], [2, -2, 3, -3], and [1, -1, 2, -2, 3, -3]. Since there are 6 such subarrays, the output is 6.

#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    long long prefix_sum = 0;
    long long count = 0;

    // Allocate large array for storing prefix sums
    // Range assumption: sum won't exceed +/- 10^7
    int size = 2000001;
    long long *freq = (long long*)calloc(size, sizeof(long long));

    int offset = 1000000;   // To handle negative sums
    freq[offset] = 1;       // prefix_sum = 0 initially

    for(int i = 0; i < n; i++) {
        prefix_sum += arr[i];

        if(prefix_sum + offset >= 0 && prefix_sum + offset < size) {
            count += freq[prefix_sum + offset];
            freq[prefix_sum + offset]++;
        }
    }

    printf("%lld\n", count);

    free(freq);
    return 0;
}
