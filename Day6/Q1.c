#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    if (n == 0) return 0;

    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // print first element
    printf("%d ", arr[0]);

    // print only when value changes
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[i - 1]) {
            printf("%d ", arr[i]);
        }
    }

    return 0;
}
