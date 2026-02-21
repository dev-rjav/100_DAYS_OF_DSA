
#include <stdio.h>

int main() {
    int arr[5] = {1, 2, 3, 4, 5};
    int product = 1;

    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            if (i != j) {
                product *= arr[j];
            }
        }
        printf("%d ", product);
    }

    return 0;
}