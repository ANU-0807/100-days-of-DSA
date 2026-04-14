#include <stdio.h>
#include <string.h>

#define MAX 100

int table[MAX];

// Initialize table
void init(int m) {
    for (int i = 0; i < m; i++) {
        table[i] = -1;
    }
}

// Insert using quadratic probing
void insert(int key, int m) {
    int index = key % m;

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == -1) {
            table[newIndex] = key;
            return;
        }
    }
}

// Search
void search(int key, int m) {
    int index = key % m;

    for (int i = 0; i < m; i++) {
        int newIndex = (index + i * i) % m;

        if (table[newIndex] == key) {
            printf("FOUND\n");
            return;
        }

        if (table[newIndex] == -1) {
            break;
        }
    }

    printf("NOT FOUND\n");
}

int main() {
    int m, q;

    scanf("%d", &m);
    scanf("%d", &q);

    init(m);

    char op[10];  // IMPORTANT FIX
    int key;

    for (int i = 0; i < q; i++) {
        scanf("%s", op);

        if (strcmp(op, "INSERT") == 0) {
            scanf("%d", &key);
            insert(key, m);
        }
        else if (strcmp(op, "SEARCH") == 0) {
            scanf("%d", &key);
            search(key, m);
        }
    }

    return 0;
}
