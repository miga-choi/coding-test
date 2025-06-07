#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* selfDividingNumbers(int left, int right, int* returnSize) {
    *returnSize = 0;
    int* result = (int*)malloc(sizeof(int) * (right - left + 1));

    for (int i = left; i <= right; i++) {
        int v = i;

        while (v > 0) {
            if (v % 10 == 0 || i % (v % 10) > 0) {
                break;
            }

            v /= 10;
        }

        if (v == 0) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}


// Solution
int *solution(int left, int right, int *returnSize) {
    *returnSize = 0;
    int *result = (int *)malloc(sizeof(int) * (right - left + 1));

    for (int i = left, n = 0; i <= right; i++) {
        for (n = i; n > 0; n /= 10) {
            if (n % 10 == 0 || i % (n % 10) != 0) {
                break;
            }
        }

        if (n == 0) {
            result[(*returnSize)++] = i;
        }
    }

    return result;
}
