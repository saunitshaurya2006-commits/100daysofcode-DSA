#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

/* Create new node */
struct Node* createNode(int data) {
    struct Node* newNode =
        (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

/* Insert at end */
struct Node* insert(struct Node* head, int data) {
    struct Node* newNode = createNode(data);

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

/* Find length of list */
int getLength(struct Node* head) {
    int count = 0;
    while (head != NULL) {
        count++;
        head = head->next;
    }
    return count;
}

/* Find intersection */
void findIntersection(struct Node* head1,
                      struct Node* head2) {

    int len1 = getLength(head1);
    int len2 = getLength(head2);

    struct Node *p1 = head1, *p2 = head2;
    int diff;

    if (len1 > len2) {
        diff = len1 - len2;
        while (diff--)
            p1 = p1->next;
    } else {
        diff = len2 - len1;
        while (diff--)
            p2 = p2->next;
    }

    while (p1 && p2) {
        if (p1->data == p2->data) {
            printf("%d", p1->data);
            return;
        }
        p1 = p1->next;
        p2 = p2->next;
    }

    printf("No Intersection");
}

int main() {
    int n, m, x;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &x);
        head1 = insert(head1, x);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &x);
        head2 = insert(head2, x);
    }

    findIntersection(head1, head2);

    return 0;
}
