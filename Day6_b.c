#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int nums[n];

    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    int j = 0;  // position for next non-zero

    // Move non-zero elements forward
    for (int i = 0; i < n; i++) {
        if (nums[i] != 0) {
            nums[j] = nums[i];
            j++;
        }
    }

    // Fill remaining positions with 0
    while (j < n) {
        nums[j] = 0;
        j++;
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
