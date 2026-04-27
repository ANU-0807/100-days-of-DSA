#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    // Edge case
    if (n == 0) {
        printf("0");
        return 0;
    }

    int left = 1, right = n;
    int ans = 0;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (mid <= n / mid) {
            ans = mid;        // possible answer
            left = mid + 1;   // try bigger
        } else {
            right = mid - 1;  // go smaller
        }
    }

    printf("%d", ans);
    return 0;
}
