#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    int start[] = {0, 5, 15};
    int end[]   = {30, 10, 20};
    int n = 3;

    qsort(start, n, sizeof(int), cmp);
    qsort(end, n, sizeof(int), cmp);

    int i = 0, j = 0, rooms = 0, maxRooms = 0;

    while (i < n && j < n) {
        if (start[i] < end[j]) {
            rooms++;
            if (rooms > maxRooms) maxRooms = rooms;
            i++;
        } else {
            rooms--;
            j++;
        }
    }

    printf("Minimum Rooms = %d\n", maxRooms);
    return 0;
}
