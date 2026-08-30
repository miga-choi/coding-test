#include <stdbool.h> // bool
#include <stdlib.h>  // qsort
#include <string.h>  // memset

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Complexities:
 *   N - `nums1Size`
 *   M - `nums2Size`
 *   K - 1001 * 4 bytes
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(K)
 */
int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int count = 0;
    int numExist[1001] = {0};
    int* result = (int*)malloc(sizeof(int) * 1001);

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


// Solution
/**
 * Solution 1
 * 
 * Lookup table
 * 
 * Complexities:
 *   N - `nums1Size`
 *   M - `nums2Size`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
#define MAXV 1001

int* solution1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    bool seen[MAXV];
    memset(seen, 0, sizeof(seen));

    for (int i = 0; i < nums1Size; i++) {
        seen[nums1[i]] = true;
    }

    int cap = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* res = malloc(cap * sizeof(int));
    int cnt = 0;

    for (int i = 0; i < nums2Size; i++) {
        int v = nums2[i];
        if (seen[v]) {
            res[cnt++] = v;
            seen[v] = false;
        }
    }

    *returnSize = cnt;
    return res;
}

/**
 * Solution 2
 * 
 * Sort + Two pointers
 * 
 * Complexities:
 *   N - `nums1Size`
 *   M - `nums2Size`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
static int cmp(const void* a, const void* b) {
    int x = *(const int*)a, y = *(const int*)b;
    return (x > y) - (x < y);
}

int* solution2(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    qsort(nums1, nums1Size, sizeof(int), cmp);
    qsort(nums2, nums2Size, sizeof(int), cmp);

    int cap = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* res = malloc(cap * sizeof(int));
    int i = 0, j = 0, cnt = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            if (cnt == 0 || res[cnt - 1] != nums1[i]) {
                res[cnt++] = nums1[i];
            }
            i++;
            j++;
        }
    }

    *returnSize = cnt;
    return res;
}
