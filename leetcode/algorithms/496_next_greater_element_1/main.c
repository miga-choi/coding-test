#include <stdlib.h> // malloc

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Brute Force with Found Flag
 *
 * Complexities:
 *   n - `nums1Size`
 *   m - `nums2Size`
 *   - Time Complexity: O(n * m)
 *   - Space Complexity: O(1)
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
/**
 * Solution 1
 *
 * Brute Force
 *
 * Complexities:
 *   n - `nums1Size`
 *   m - `nums2Size`
 *   - Time Complexity: O(n * m)
 *   - Space Complexity: O(1)
 */
int* solution1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* res = malloc(nums1Size * sizeof(int));

    for (int i = 0; i < nums1Size; i++) {
        int j = 0;
        while (nums2[j] != nums1[i]) {
            j++;
        }

        res[i] = -1;
        for (j++; j < nums2Size; j++) {
            if (nums2[j] > nums1[i]) {
                res[i] = nums2[j];
                break;
            }
        }
    }

    *returnSize = nums1Size;
    return res;
}

/**
 * Solution 2
 *
 * Monotonic Stack + Lookup Table
 *
 * Complexities:
 *   n - `nums1Size`
 *   m - `nums2Size`
 *   - Time Complexity: O(n + m)
 *   - Space Complexity: O(m)
 */
#define MAXV 10001

int* solution2(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int next[MAXV];
    memset(next, -1, sizeof(next));

    int* st = malloc(nums2Size * sizeof(int));
    int top = 0;

    for (int i = 0; i < nums2Size; i++) {
        int x = nums2[i];
        while (top > 0 && st[top - 1] < x) {
            next[st[--top]] = x;
        }
        st[top++] = x;
    }
    free(st);

    int* res = malloc(nums1Size * sizeof(int));
    for (int i = 0; i < nums1Size; i++) {
        res[i] = next[nums1[i]];
    }

    *returnSize = nums1Size;
    return res;
}
