#include <stdlib.h> // malloc, qsort

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

/**
 * Complexities:
 *   N - `nums1Size`
 *   M - `nums2Size`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(K)
 */
int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* result = (int*)malloc(sizeof(int) * 1000);
    int count = 0;

    for (int i = 0; i < nums1Size; i++) {
        for (int j = 0; j < nums2Size; j++) {
            if (nums1[i] >= 0 && nums2[j] >= 0 && nums1[i] == nums2[j]) {
                result[count] = nums1[i];
                nums1[i] = -1;
                nums2[j] = -1;
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
 * Counting Array
 * 
 * Complexities:
 *   N - `nums1Size`
 *   M - `nums2Size`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
#define MAXV 1001

int* solution1(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int cnt[MAXV] = {0};

    for (int i = 0; i < nums1Size; i++) {
        cnt[nums1[i]]++;
    }

    int cap = nums1Size < nums2Size ? nums1Size : nums2Size;
    int* res = malloc(cap * sizeof(int));
    int k = 0;

    for (int i = 0; i < nums2Size; i++) {
        int v = nums2[i];
        if (cnt[v] > 0) {
            res[k++] = v;
            cnt[v]--;
        }
    }

    *returnSize = k;
    return res;
}

/**
 * Solution 2
 * 
 * Sorting + Two Pointers
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
    int i = 0, j = 0, k = 0;

    while (i < nums1Size && j < nums2Size) {
        if (nums1[i] < nums2[j]) {
            i++;
        } else if (nums1[i] > nums2[j]) {
            j++;
        } else {
            res[k++] = nums1[i];
            i++;
            j++;
        }
    }

    *returnSize = k;
    return res;
}
