#include <stdio.h>

void merge(int nums1[], int m, int nums2[], int n) {
    int i = m - 1;        // pointer for nums1
    int j = n - 1;        // pointer for nums2
    int k = m + n - 1;    // pointer for merged array (nums1)

    // Merge from the end
    while (i >= 0 && j >= 0) {
        if (nums1[i] > nums2[j]) {
            nums1[k] = nums1[i];
            i--;
        } else {
            nums1[k] = nums2[j];
            j--;
        }
        k--;
    }

    // Copy remaining elements from nums2 (if any)
    while (j >= 0) {
        nums1[k] = nums2[j];
        j--;
        k--;
    }
}

int main() {
    int m, n;
    scanf("%d %d", &m, &n);

    int nums1[m + n];
    int nums2[n];

    // Input nums1 (first m elements)
    for (int i = 0; i < m; i++) {
        scanf("%d", &nums1[i]);
    }

    // Remaining n elements are 0 (ignored)
    for (int i = m; i < m + n; i++) {
        nums1[i] = 0;
    }

    // Input nums2
    for (int i = 0; i < n; i++) {
        scanf("%d", &nums2[i]);
    }

    merge(nums1, m, nums2, n);

    // Print merged nums1
    for (int i = 0; i < m + n; i++) {
        printf("%d ", nums1[i]);
    }

    return 0;
}
