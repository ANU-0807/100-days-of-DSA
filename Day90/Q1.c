#include <stdio.h>

int canPaint(int boards[], int n, int k, int maxTime) {
    int painters = 1, curr = 0;

    for (int i = 0; i < n; i++) {
        if (curr + boards[i] <= maxTime) {
            curr += boards[i];
        } else {
            painters++;
            curr = boards[i];
        }
    }
    return painters <= k;
}

int minTime(int boards[], int n, int k) {
    int low = 0, high = 0;

    for (int i = 0; i < n; i++) {
        if (boards[i] > low) low = boards[i];
        high += boards[i];
    }

    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;

        if (canPaint(boards, n, k, mid)) {
            ans = mid;
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return ans;
}

int main() {
    int n = 4, k = 2;
    int boards[] = {10, 20, 30, 40};

    printf("%d\n", minTime(boards, n, k));
    return 0;
}
