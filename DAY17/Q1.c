#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int x;
    scanf("%d", &x);

    int max = x;
    int min = x;

    for (int i = 1; i < n; i++) {
        scanf("%d", &x);

        if (x > max) max = x;
        if (x < min) min = x;
    }

    printf("Max: %d\n", max);
    printf("Min: %d", min);

    return 0;
}
