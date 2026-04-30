#include <stdio.h>

// Check if allocation is possible
int canAllocate(int arr[], int n, int m, int maxPages) {
    int students = 1;
    int pages = 0;

    for (int i = 0; i < n; i++) {
        if (pages + arr[i] > maxPages) {
            students++;
            pages = arr[i];
        } else {
            pages += arr[i];
        }
    }

    return students <= m;
}

int findPages(int arr[], int n, int m) {
    if (m > n) return -1;

    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (arr[i] > low)
            low = arr[i];
        high += arr[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = low + (high - low) / 2;

        if (canAllocate(arr, n, m, mid)) {
            ans = mid;
            high = mid - 1;  // try smaller
        } else {
            low = mid + 1;   // increase
        }
    }

    return ans;
}

int main() {
    int arr[] = {12, 34, 67, 90};
    int n = 4, m = 2;

    printf("%d\n", findPages(arr, n, m)); // Output: 113
    return 0;
}
