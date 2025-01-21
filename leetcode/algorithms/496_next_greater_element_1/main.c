#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* numsBool = (int*)calloc(nums1Size, sizeof(int));
    int* result = (int*)malloc(sizeof(int) * nums1Size);
    for (int i = 0; i < nums1Size; i++) {
        result[i] = -1;
        for (int j = 0; j < nums2Size; j++) {
            if (numsBool[i] == 1 && nums2[j] > nums1[i]) {
                result[i] = nums2[j];
                numsBool[i] = 0;
            } else if (nums1[i] == nums2[j]) {
                numsBool[i] = 1;
            }
        }
    }
    *returnSize = nums1Size;
    return result;
}

// Solution
int* solution(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(nums1Size * sizeof(int));
    *returnSize = nums1Size;
    int count = 0;
    int temp[10000] = {0};
    for (int i = 0; i < nums2Size; i++) {
        temp[nums2[i]] = i;
    }
    for (int i = 0; i < nums1Size; i++) {
        int j;
        for (j = temp[nums1[i]] + 1; j < nums2Size; j++) {
            if (nums2[j] > nums1[i]) {
                result[count++] = nums2[j];
                break;
            }
        }
        if (j == nums2Size) {
            result[count++] = -1;
        }
    }
    return result;
}
