#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *intersection(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    int count = 0;
    int numExist[1001] = {0};
    int *result = (int *)malloc(sizeof(int) * 1001);
    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (!numExist[nums1[i]] && nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                numExist[nums1[i]] = 1;
                count++;
            }
        }
    }
    *returnSize = count;
    return result;
}

// Best Solution
int *bestSolution(int *nums1, int nums1Size, int *nums2, int nums2Size, int *returnSize) {
    int *map = malloc(sizeof(int) * 1000);
    int *res = malloc(sizeof(int) * 1000);
    int cnt = 0;

    for (int i = 0; i < nums1Size; i++) {
        map[nums1[i]] = 1;
    }
    for (int i = 0; i < nums2Size; i++) {
        if (map[nums2[i]] == 1) {
            res[cnt++] = nums2[i];
            map[nums2[i]] = 0;
        }
    }
    *returnSize = cnt;
    return res;
}
