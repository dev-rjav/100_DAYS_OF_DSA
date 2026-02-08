#include <stdio.h>

int removeElement(int nums[], int n, int val) {
    int i = 0;

    while (i < n) {
        if (nums[i] == val) {
            nums[i] = nums[n - 1];  // replace with last element
            n--;                    // reduce array size
        } else {
            i++;
        }
    }
    return n; // number of elements not equal to val
}

int main() {
    int n, val;
    scanf("%d", &n);

    int nums[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums[i]);
    }

    scanf("%d", &val);

    int k = removeElement(nums, n, val);

    // Print first k elements
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }

    return 0;
}
