#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Two Pointers
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
char** summaryRanges(int* nums, int numsSize, int* returnSize) {
    char** stringArray = (char**)malloc(sizeof(char*) * 20);

    int count = 0;
    *returnSize = 0;

    if (numsSize > 0) {
        int begin = nums[0];

        for (int i = 1; i < numsSize; i++) {
            if ((nums[i] - 1) > nums[i - 1]) {
                stringArray[count] = (char*)malloc(sizeof(char) * 30);
                if (begin < nums[i - 1]) {
                    snprintf(stringArray[count], 30, "%d->%d", begin, nums[i - 1]);
                } else {
                    snprintf(stringArray[count], 30, "%d", begin);
                }
                begin = nums[i];
                count++;
            }
        }

        stringArray[count] = (char*)malloc(sizeof(char) * 30);

        if (begin < nums[numsSize - 1]) {
            snprintf(stringArray[count], 30, "%d->%d", begin, nums[numsSize - 1]);
        } else {
            snprintf(stringArray[count], 30, "%d", begin);
        }

        *returnSize = count + 1;
    }

    return stringArray;
}


// Solution
/**
 * Two Pointers
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
char** solution(int* nums, int numsSize, int* returnSize) {
    if (numsSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    char** result = (char**)malloc(sizeof(char*) * numsSize);
    int count = 0;

    int i = 0;
    while (i < numsSize) {
        int start = i;

        while (i + 1 < numsSize && (long long)nums[i + 1] - nums[i] == 1) {
            i++;
        }
        int end = i;

        char* rangeStr = (char*)malloc(sizeof(char) * 25);
        
        if (start == end) {
            snprintf(rangeStr, 25, "%d", nums[start]);
        } else {
            snprintf(rangeStr, 25, "%d->%d", nums[start], nums[end]);
        }

        result[count++] = rangeStr;
        i++;
    }

    *returnSize = count;

    result = (char**)realloc(result, sizeof(char*) * count);

    return result;
}
