// Rotate Linked List Right by k Places - Implement using linked list with dynamic memory allocation.

// Input:
// - First line: integer n
// - Second line: n space-separated integers
// - Third line: integer k

// Output:
// - Print the linked list elements after rotation, space-separated

// Example:
// Input:
// 5
// 10 20 30 40 50
// 2

// Output:
// 40 50 10 20 30

// Explanation:
// Connect last node to head forming circular list. Traverse to (n-k)th node, set next to NULL, update head to (n-k+1)th node.

#include <stdio.h>
#include <stdlib.h>

// Node structure
struct Node
{
    int data;
    struct Node* next;
};

// Function to create node dynamically
struct Node* createNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Insert at end
struct Node* insertEnd(struct Node* head, int data)
{
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

// Rotate linked list right by k places
struct Node* rotateRight(struct Node* head, int n, int k)
{
    if (head == NULL || k == 0)
        return head;

    k = k % n;   // handle k > n
    if (k == 0)
        return head;

    struct Node *temp = head;
    int count = 1;

    // go to last node
    while (temp->next != NULL)
    {
        temp = temp->next;
        count++;
    }

    // make circular linked list
    temp->next = head;

    // move to (n-k)th node
    int steps = n - k;
    temp = head;

    for (int i = 1; i < steps; i++)
        temp = temp->next;

    // new head
    head = temp->next;

    // break circular link
    temp->next = NULL;

    return head;
}

// Display list
void display(struct Node* head)
{
    struct Node* temp = head;
    while (temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
}

// Main function
int main()
{
    int n, x, k;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%d", &x);
        head = insertEnd(head, x);
    }

    scanf("%d", &k);

    head = rotateRight(head, n, k);

    display(head);

    return 0;
}
