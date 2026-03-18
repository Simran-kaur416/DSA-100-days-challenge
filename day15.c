#include <stdio.h>

int main() {
    int m, n, i, j;
    
    // Input rows and columns
    scanf("%d %d", &m, &n);
    
    int matrix[m][n];
    
    // Input matrix elements
    for(i = 0; i < m; i++) {
        for(j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    
    int sum = 0;
    
    // Calculate primary diagonal sum
    for(i = 0; i < m && i < n; i++) {
        sum += matrix[i][i];
    }
    
    // Output result
    printf("%d", sum);
    
    return 0;
}