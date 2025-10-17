#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * (digitsSize + 1));

    int up = 1;
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i] += up;
        up = 0;

        if (digits[i] > 9) {
            result[i + 1] = digits[i] - 10;
            up = 1;
        } else {
            result[i + 1] = digits[i];
        }
    }

    *returnSize = digitsSize;
    if (up > 0) {
        result[0] = 1;
        (*returnSize)++;
        return result;
    }

    return result + 1;
}


// Solution
/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 */
int* solution(int* digits, int digitsSize, int* returnSize) {
    for (int i = digitsSize - 1; i >= 0; i--) {
        digits[i]++;

        if (digits[i] < 10) {
            int* result = (int*)malloc(sizeof(int) * digitsSize);
            memcpy(result, digits, sizeof(int) * digitsSize);
            *returnSize = digitsSize;
            return result;
        }

        digits[i] = 0;
    }

    *returnSize = digitsSize + 1;
    int* result = (int*)malloc(sizeof(int) * (*returnSize));

    result[0] = 1;
    for (int i = 1; i < *returnSize; i++) {
        result[i] = 0;
    }

    return result;
}
