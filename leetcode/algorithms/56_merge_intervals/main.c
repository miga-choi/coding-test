#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */

int compare(const void* a, const void* b) {
    int* intervalA = *(int**)a;
    int* intervalB = *(int**)b;
    return intervalA[0] - intervalB[0];
}

/**
 * Sorting
 * 
 * Complexities:
 *   N - intervalsSize
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
int** merge(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);

    int idx = 0;
    result[idx] = (int*)malloc(sizeof(int) * 2);
    result[idx][0] = intervals[0][0];
    result[idx][1] = intervals[0][1];

    for (int i = 1; i < intervalsSize; i++) {
        int* last = result[idx];
        int* curr = intervals[i];

        if (last[1] >= curr[0]) {
            if (last[1] < curr[1]) {
                last[1] = curr[1];
            }
        } else {
            idx++;
            result[idx] = (int*)malloc(sizeof(int) * 2);
            result[idx][0] = curr[0];
            result[idx][1] = curr[1];
        }
    }

    *returnSize = idx + 1;

    *returnColumnSizes = (int*)malloc(sizeof(int) * (*returnSize));
    for (int i = 0; i < *returnSize; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}


// Solution
/**
 * Sorting
 * 
 * Complexities:
 *   N - intervalsSize
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
int** solution(int** intervals, int intervalsSize, int* intervalsColSize, int* returnSize, int** returnColumnSizes) {
    qsort(intervals, intervalsSize, sizeof(int*), compare);

    int** result = (int**)malloc(sizeof(int*) * intervalsSize);
    int count = 0;

    result[count] = (int*)malloc(sizeof(int) * 2);
    result[count][0] = intervals[0][0];
    result[count][1] = intervals[0][1];
    count++;

    for (int i = 1; i < intervalsSize; i++) {
        int* last = result[count - 1];
        int* curr = intervals[i];

        if (curr[0] <= last[1]) {
            if (curr[1] > last[1]) {
                last[1] = curr[1];
            }
        } else {
            result[count] = (int*)malloc(sizeof(int) * 2);
            result[count][0] = curr[0];
            result[count][1] = curr[1];
            count++;
        }
    }

    *returnSize = count;

    *returnColumnSizes = (int*)malloc(sizeof(int) * count);
    for (int i = 0; i < count; i++) {
        (*returnColumnSizes)[i] = 2;
    }

    return result;
}
