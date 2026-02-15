#include <stdio.h>
#include <stdlib.h>

int main() {
    int r, c;
    scanf("%d %d", &r, &c);

    int matrix[r][c];

    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int visited[r * c];
    memset(visited, 0, sizeof(visited));

    int top_left = r - 1;
    while (top_left != -1) {
        int row = top_left / c;
        int col = top_left % c;
        if (visited[row * c + col]) continue;

        printf("%d ", matrix[row][col]);
        visited[row * c + col] = 1;

        top_left--;
        row++;
    }

    return 0;
}