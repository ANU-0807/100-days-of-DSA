#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int start, end;
} Interval;

int cmp(const void *a, const void *b) {
    return ((Interval*)a)->start - ((Interval*)b)->start;
}

int main() {
    Interval arr[] = {{1,3},{2,6},{8,10},{15,18}};
    int n = 4;

    qsort(arr, n, sizeof(Interval), cmp);

    int s = arr[0].start, e = arr[0].end;

    for (int i = 1; i < n; i++) {
        if (arr[i].start <= e) {
            if (arr[i].end > e)
                e = arr[i].end;
        } else {
            printf("[%d, %d] ", s, e);
            s = arr[i].start;
            e = arr[i].end;
        }
    }
    printf("[%d, %d]\n", s, e);

    return 0;
}
