#include <stdio.h>
#include <stdlib.h>

// Function to swap two elements in an array
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to rotate an image by 90 degrees
void rotateImage(int** img, int rows, int cols) {
    // Initialize a new array for the rotated image
    int* newImg = malloc(rows * sizeof(int));
    
    // Loop through each row of the image and store it in the new array
    for (int i = 0; i < rows; i++) {
        swap(&newImg[i], &img[cols - 1][i]);
    }

    // Copy the rotated array back into the original image
    for (int i = 0; i < rows; i++) {
        swap(&img[i][0], &newImg[i]);
    }
}

int main() {
    int rows, cols;

    printf("Enter the number of rows: ");
    scanf("%d", &rows);

    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate memory for the image and read in its values
    int** img = malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        img[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            printf("Enter the value at (%d, %d): ", i + 1, j + 1);
            scanf("%d", &img[i][j]);
        }
    }

    // Rotate the image by 90 degrees
    rotateImage(img, rows, cols);

    // Print out the rotated image in proper formatting
    printf("\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d ", img[i][j]);
        }
        printf("\n");
    }

    // Free memory allocated for the image and its rows
    for (int i = 0; i < rows; i++) {
        free(img[i]);
    }
    free(img);

    return 0;
}