#include <stdio.h>

#define MAX 1000

int main() {
    int n;
    scanf("%d", &n);

    int arr[MAX];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int sum = 0, maxLen = 0;

    // Hash map (simulate using array)
    int hash[20001];
    for (int i = 0; i < 20001; i++) {
        hash[i] = -2;  // -2 means not visited
    }

    // Offset to handle negative sums
    int offset = 10000;

    for (int i = 0; i < n; i++) {
        sum += arr[i];

        if (sum == 0) {
            maxLen = i + 1;
        }

        if (hash[sum + offset] != -2) {
            int prevIndex = hash[sum + offset];
            int length = i - prevIndex;
            if (length > maxLen) {
                maxLen = length;
            }
        } else {
            hash[sum + offset] = i;
        }
    }

    printf("%d\n", maxLen);

    return 0;
}
