/**
 * Two Pointers
 * 
 * Complexities:
 *   N - Length of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int removeDuplicates(int* nums, int numsSize) {
    int left = 0;

    for (int right = 0; right < numsSize; right++) {
        if (nums[left] != nums[right]) {
            nums[++left] = nums[right];
        }
    }

    return left + 1;
}


// Solution
/**
 * Two Pointers
 * 
 * Complexities:
 *   N - Length of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(int* nums, int numsSize) {
    int i = 0;

    for (int j = 1; j < numsSize; j++) {
        if (nums[j] != nums[i]) {
            i++;
            nums[i] = nums[j];
        }
    }

    return i + 1;
}
