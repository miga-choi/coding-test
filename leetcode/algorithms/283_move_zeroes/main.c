/**
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
void moveZeroes(int* nums, int numsSize) {
    int newNums[numsSize];
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i]) {
            newNums[count++] = nums[i];
        }
    }

    for (int i = 0; i < count; i++) {
        nums[i] = newNums[i];
    }

    for (int i = 1; i <= numsSize - count; i++) {
        nums[numsSize - i] = 0;
    }
}


// Solution
/**
 * Two Pointers Swap
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
void solution(int* nums, int numsSize) {
    int lastNonZeroFoundAt = 0;

    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            if (i != lastNonZeroFoundAt) {
                int temp = nums[lastNonZeroFoundAt];
                nums[lastNonZeroFoundAt] = nums[i];
                nums[i] = temp;
            }

            lastNonZeroFoundAt++;
        }
    }
}
