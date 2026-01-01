#include <stdbool.h>

/**
 * Two Pointers
 * 
 * Complexities:
 *   N - numsSize
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int removeElement(int* nums, int numsSize, int val) {
    int i = 0;

    for (int j = 0; j < numsSize; j++) {
        if (nums[j] != val) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
            i++;
        }
    }

    return i;
}


// Solution
/**
 * Two Pointers
 * 
 * Complexities:
 *   N - numsSize
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(int* nums, int numsSize, int val) {
    int k = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }

    return k;
}
