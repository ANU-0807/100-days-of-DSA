#include <stdio.h>

int merge(int arr[], int l, int m, int r) {
    int temp[1000];
    int i = l, j = m + 1, k = 0, inv = 0;

    while (i <= m && j <= r) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else {
            temp[k++] = arr[j++];
            inv += (m - i + 1);
        }
    }

    while (i <= m) temp[k++] = arr[i++];
    while (j <= r) temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[l + i] = temp[i];

    return inv;
}

int mergeSort(int arr[], int l, int r) {
    int inv = 0;
    if (l < r) {
        int m = (l + r) / 2;
        inv += mergeSort(arr, l, m);
        inv += mergeSort(arr, m + 1, r);
        inv += merge(arr, l, m, r);
    }
    return inv;
}

int main() {
    int arr[] = {2, 4, 1, 3, 5};
    int n = 5;

    printf("Inversions = %d\n", mergeSort(arr, 0, n - 1));
    return 0;
}
