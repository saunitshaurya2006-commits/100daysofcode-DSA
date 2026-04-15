// Given an array of candidate names where each name represents a vote cast for that candidate, determine the candidate who received the maximum number of votes. In case of a tie, return the lexicographically smallest candidate name.

// Input Format
// First line contains an integer n representing number of votes.
// Second line contains n space-separated strings representing candidate names.

// Output Format
// Print the name of the winning candidate followed by the number of votes received.

// Sample Input
// 13
// john johnny jackie johnny john jackie jamie jamie john johnny jamie johnny john

// Sample Output
// john 4

// Explanation
// Both john and johnny receive 4 votes, but john is lexicographically smaller, so john is declared the winner.

#include <stdio.h>
#include <string.h>

int main() {
    int n;
    scanf("%d", &n);

    char votes[1000][100];
    
    for (int i = 0; i < n; i++) {
        scanf("%s", votes[i]);
    }

    char winner[100];
    int maxVotes = 0;

    for (int i = 0; i < n; i++) {
        int count = 0;

        // Count occurrences of votes[i]
        for (int j = 0; j < n; j++) {
            if (strcmp(votes[i], votes[j]) == 0) {
                count++;
            }
        }

        // Update winner if needed
        if (count > maxVotes) {
            maxVotes = count;
            strcpy(winner, votes[i]);
        } 
        else if (count == maxVotes) {
            if (strcmp(votes[i], winner) < 0) {
                strcpy(winner, votes[i]);
            }
        }
    }

    printf("%s %d\n", winner, maxVotes);

    return 0;
}
