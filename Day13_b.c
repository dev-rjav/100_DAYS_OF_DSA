#include <stdio.h>

int main() {
    int m, n;

    printf("Enter rows: ");
    scanf("%d", &m);
    printf("Enter columns: ");
    scanf("%d", &n);

    int matrix[m][n];

    for (int i = 0; i < m; i++) {
        printf("Enter row %d elements:\n", i+1);

        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    // Spiral Matrix

    for (int i = 0, j = m-1; i < n && j >= 0; i++, j--) {
        printf("%d ", matrix[i][j]);
    }

    return 0;
}

Input:

Enter rows: 5
Enter columns: 5

Enter row 1 elements:
1
2
3
4
5

Enter row 2 elements:
6
7
8
9
10

Enter row 3 elements:
11
12
13
14
15

Enter row 4 elements:
16
17
18
19
20

Enter row 5 elements:
21
22
23
24
25

Output:css
1 2 3 4 5
6 7 8 9 10
11 12 13 14 15
16 17 18 19 20
21 22 23 24 25