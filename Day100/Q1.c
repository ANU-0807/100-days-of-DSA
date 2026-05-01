#include <stdio.h>

int main() {
    int arr[] = {5,2,6,1};
    int n = 4;
    int count[100] = {0};

    for (int i = 0; i < n; i++) {
        int c = 0;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[i])
                c++;
        }
        count[i] = c;
    }

    for (int i = 0; i < n; i++)
        printf("%d ", count[i]);

    return 0;
}
