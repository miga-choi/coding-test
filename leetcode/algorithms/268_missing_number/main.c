/**
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int missingNumber(int *nums, int numsSize) {
    int sum = 0;
    int originSum = 0;

    for (int i = 0; i <= numsSize; i++) {
        originSum += i;
        if (i < numsSize) {
            sum += nums[i];
        }
    }

    return originSum - sum;
}


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution1(int *nums, int numsSize) {
    int n = numsSize;
    
    int expectedSum = n * (n + 1) / 2;
    
    int actualSum = 0;
    for (int i = 0; i < n; i++) {
        actualSum += nums[i];
    }
    
    return expectedSum - actualSum;
}

/**
 * Solution 2
 * 
 * XOR
 * 
 * Complexities:
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
int solution2(int *nums, int numsSize) {
    int missing = numsSize;

    for (int i = 0; i < numsSize; i++) {
        missing ^= i ^ nums[i];
    }

    return missing;
}
