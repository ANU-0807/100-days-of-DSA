#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insert(struct Node* head, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;

    if (head == NULL)
        return newNode;

    struct Node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

int main() {
    int n, m, value;
    struct Node *head1 = NULL, *head2 = NULL;

    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head1 = insert(head1, value);
    }

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
        scanf("%d", &value);
        head2 = insert(head2, value);
    }

    struct Node* p1 = head1;

    while (p1 != NULL) {
        struct Node* p2 = head2;

        while (p2 != NULL) {
            if (p1->data == p2->data) {
                printf("%d", p1->data);
                return 0;
            }
            p2 = p2->next;
        }

        p1 = p1->next;
    }

    printf("No Intersection");

    return 0;
}
