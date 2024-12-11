#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000);
    int count = 0;
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] >= 0 && nums2[j] >= 0 && nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                nums1[i] = -1;
                nums2[j] = -1;
                count++;
            }
        }
    }
    *returnSize = count;
    return result;
}

// Best Solution
int* bestSolution(int* nums1, int nums1size, int* nums2, int nums2size, int* returnsize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int i = 0, j = 0, count = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] > nums2[j]) {
            j++;
        } else if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] == nums2[j]) {
            nums1[count] = nums1[i];
            count++;
            i++;
            j++;
        }
    }

    *returnSize = count;
    return nums1;
}
