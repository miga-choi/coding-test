#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findErrorNums(int* nums, int numsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 2);

    for (int i = 1; i <= numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == i) {
                count++;
            }
        }
        if (count == 2) {
            result[0] = i;
        }
        if (count == 0) {
            result[1] = i;
        }
    }

    *returnSize = 2;
    return result;
}

// Solution
int* solution(int* nums, int numsSize, int* returnSize) {
    int dup = -1, missing = -1;

    for (int i = 1; i <= numsSize; i++) {
        int count = 0;
        for (int j = 0; j < numsSize; j++) {
            if (nums[j] == i) {
                count++;
            }
        }
        if (count == 2) {
            dup = i;
        } else if (count == 0) {
            missing = i;
        }
    }
    
    int* result = (int*)malloc(sizeof(int) * 2);
    result[0] = dup;
    result[1] = missing;

    *returnSize = 2;
    return result;
}
