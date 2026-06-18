#include <stdlib.h>
#include <stdbool.h>

/**
 * Brute Force (Time Limit Exceeded)
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N * K)
 *   - Space Complexity: O(1)
 */
bool containsNearbyDuplicate(int* nums, int numsSize, int k) {
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] == nums[j] && abs(i - j) <= k) {
                return true;
            }
        }
    }

    return false;
}


// Solution
/**
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
typedef struct {
    int val;
    int index;
} Element;

int compare(const void* a, const void* b) {
    Element* elemA = (Element*)a;
    Element* elemB = (Element*)b;

    if (elemA->val < elemB->val) {
        return -1;
    }
    if (elemA->val > elemB->val) {
        return 1;
    }

    return elemA->index - elemB->index;
}

bool solution(int* nums, int numsSize, int k) {
    if (numsSize <= 1 || k <= 0) {
        return false;
    }

    Element* arr = (Element*)malloc(sizeof(Element) * numsSize);
    if (arr == NULL) {
        return false;
    }

    for (int i = 0; i < numsSize; i++) {
        arr[i].val = nums[i];
        arr[i].index = i;
    }

    qsort(arr, numsSize, sizeof(Element), compare);

    for (int i = 0; i < numsSize - 1; i++) {
        if (arr[i].val == arr[i + 1].val) {
            if (abs(arr[i].index - arr[i + 1].index) <= k) {
                free(arr);
                return true;
            }
        }
    }

    free(arr);

    return false;
}
