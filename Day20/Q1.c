#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int prefix = 0;
    int count = 0;

    // Since prefix sum range can be large, use bigger offset
    int freq[20001] = {0};  
    int offset = 10000;     

    freq[offset] = 1;  // prefix sum 0 seen once

    for (int i = 0; i < n; i++) {
        prefix += arr[i];

        if (freq[prefix + offset] > 0)
            count += freq[prefix + offset];

        freq[prefix + offset]++;
    }

    printf("%d", count);

    return 0;
}
