#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

// Insert at end
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

// Delete first occurrence of key
struct Node* deleteKey(struct Node* head, int key) {

    if (head == NULL)
        return head;

    // If key is at head
    if (head->data == key) {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    struct Node* prev = head;
    struct Node* curr = head->next;

    while (curr != NULL) {
        if (curr->data == key) {
            prev->next = curr->next;
            free(curr);
            break;   // delete only first occurrence
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

int main() {
    int n, value, key;
    struct Node* head = NULL;

    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        head = insert(head, value);
    }

    scanf("%d", &key);

    head = deleteKey(head, key);

    // Print updated list
    struct Node* temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}
