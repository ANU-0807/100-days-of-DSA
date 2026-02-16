#include <stdio.h>

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int matrix[m][n];
    int diag_sum = 0;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    for (int i = 0; i < m && i < n; i++) {
        diag_sum += matrix[i][i];
    }

    printf("%d\n", diag_sum);

    return 0;
}
