void rotateImage(int** img, int rows, int cols) {
    int** rotated = malloc(cols * sizeof(int*));

    for (int i = 0; i < cols; i++) {
        rotated[i] = malloc(rows * sizeof(int));
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            rotated[j][rows - 1 - i] = img[i][j];
        }
    }

    printf("\nRotated Image:\n");
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++) {
            printf("%d ", rotated[i][j]);
        }
        printf("\n");
    }

    for (int i = 0; i < cols; i++) {
        free(rotated[i]);
    }
    free(rotated);
}
