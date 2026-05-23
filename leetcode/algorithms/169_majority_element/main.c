/**
 * Boyer-Moore Voting Algorithm
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int majorityElement(int* nums, int numsSize) {
    int result;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            result = nums[i];
        }

        if (result == nums[i]) {
            count++;
        } else {
            count--;
        }
    }

    return result;
}


// Solution
/**
 * Boyer-Moore Voting Algorithm
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(int* nums, int numsSize) {
    int candidate = 0;
    int count = 0;

    for (int i = 0; i < numsSize; i++) {
        if (count == 0) {
            candidate = nums[i];
        }

        if (nums[i] == candidate) {
            count++;
        } else {
            count--;
        }
    }

    return candidate;
}
