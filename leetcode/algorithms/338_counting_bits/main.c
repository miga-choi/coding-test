#include <stdlib.h>

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int *countBits(int n, int *returnSize) {
    *returnSize = n + 1;
    int *result = (int *)malloc(sizeof(int) * (*returnSize));
    result[0] = 0;
    for (int i = 1; i < *returnSize; i++) {
        result[i] = (i & 1) ? result[i >> 1] + 1 : result[i >> 1];
    }
    return result;
}

// Best Solution
int *bestSolution(int n, int *returnSize) {
    n++;
    *returnSize = n;
    int *arr = (int *)malloc(sizeof(int) * n);
    arr[0] = 0;
    for (int i = 1; i < n; i++)
        arr[i] = (i & 1) ? arr[i >> 1] + 1 : arr[i >> 1];
    return arr;
}