#include <stdio.h>
#include <stdlib.h>

// comparator for sorting
int cmp(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

// check if we can place k cows with minimum distance = dist
int canPlace(int arr[], int n, int k, int dist) {
    int count = 1;        // first cow placed
    int last = arr[0];

    for(int i = 1; i < n; i++) {
        if(arr[i] - last >= dist) {
            count++;
            last = arr[i];
        }
        if(count >= k) return 1;
    }
    return 0;
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);

    int arr[n];
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // sort positions
    qsort(arr, n, sizeof(int), cmp);

    int left = 1;
    int right = arr[n - 1] - arr[0];
    int ans = 0;

    while(left <= right) {
        int mid = left + (right - left) / 2;

        if(canPlace(arr, n, k, mid)) {
            ans = mid;       // possible → try bigger
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    printf("%d", ans);
    return 0;
}
