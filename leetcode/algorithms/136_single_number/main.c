/**
 * Bit Manipulation
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int singleNumber(int* nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        result = result ^ nums[i];
    }

    return result;
}


// Solution
/**
 * XOR
 * 
 * Complexities:
 *   N - `numsSize`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution(int* nums, int numsSize) {
    int result = 0;

    for (int i = 0; i < numsSize; i++) {
        result ^= nums[i]; 
    }

    return result;
}
