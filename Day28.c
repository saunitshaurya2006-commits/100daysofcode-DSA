// Circular Linked List Creation and Traversal - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers

// Output:
// - Print the circular linked list elements starting from head, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50

// Output:
// 10 20 30 40 50

// Explanation:
// Last node's next points to head. Traverse from head until returning to head to avoid infinite loop.

#include <stdio.h>
#include <stdlib.h>

// Structure of Node
struct Node {
    int data;
    struct Node* next;
};

// Function to create circular linked list
struct Node* createCircularList(int n) {
    struct Node *head = NULL, *temp = NULL, *newNode;
    int value;

    for(int i = 0; i < n; i++) {
        scanf("%d", &value);

        // Dynamic memory allocation
        newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = value;

        if(head == NULL) {
            head = newNode;
            temp = newNode;
            newNode->next = head;   // circular link
        }
        else {
            temp->next = newNode;
            temp = newNode;
            temp->next = head;      // last node points to head
        }
    }
    return head;
}

// Function to traverse circular linked list
void traverse(struct Node* head) {
    if(head == NULL)
        return;

    struct Node* temp = head;

    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != head);   // stop when back to head
}

// Main function
int main() {
    int n;
    scanf("%d", &n);

    struct Node* head = createCircularList(n);

    traverse(head);

    return 0;
}
