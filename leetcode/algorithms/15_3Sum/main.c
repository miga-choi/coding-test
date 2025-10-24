#include <stdlib.h>
#include <stdio.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* prev, const void* next) {
    return (*(int*)prev - *(int*)next);
}

/**
 * Sort + Two-pointer
 * - Time Complexity: O(N²)
 * - Space Complexity: O(logᴺ)
 */
int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int memory_size = numsSize;
    int** result = (int**)malloc(sizeof(int*) * memory_size);
    *returnSize = 0;

    for (int flag = 0; flag < numsSize - 2; flag++) {
        if (flag > 0 && nums[flag] == nums[flag - 1]) {
            continue;
        }

        int left = flag + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[flag] + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                if (*returnSize >= memory_size) {
                    memory_size *= 2;
                    result = (int**)realloc(result, sizeof(int*) * memory_size);
                }

                int* row = (int*)malloc(sizeof(int) * 3);
                row[0] = nums[flag];
                row[1] = nums[left];
                row[2] = nums[right];
                result[*returnSize] = row;
                (*returnSize)++;

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--;
                }
            }
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}


// Solution
/**
 * Sort + Two-pointer
 * - Time Complexity: O(N²)
 * - Space Complexity: O(logᴺ)
 */
int** solution(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    qsort(nums, numsSize, sizeof(int), compare);

    int capacity = 8;
    int** result = (int**)malloc(sizeof(int*) * capacity);
    *returnSize = 0;

    for (int i = 0; i < numsSize - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = numsSize - 1;

        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];

            if (sum < 0) {
                left++;
            } else if (sum > 0) {
                right--;
            } else {
                if (*returnSize >= capacity) {
                    capacity *= 2;
                    result = (int**)realloc(result, sizeof(int*) * capacity);
                }

                result[*returnSize] = (int*)malloc(sizeof(int) * 3);
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnSize)++;

                while (left < right && nums[left] == nums[left + 1]) {
                    left++;
                }
                while (left < right && nums[right] == nums[right - 1]) {
                    right--;
                }

                left++;
                right--;
            }
        }
    }

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 3;
    }

    return result;
}
