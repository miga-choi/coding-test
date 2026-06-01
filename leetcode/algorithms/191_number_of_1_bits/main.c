/**
 * Bit Shift & Mask
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int hammingWeight(int n) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
        if (n & 1) {
            count++;
        }
        n = n >> 1;
    }

    return count;
}


// Solution
/**
 * Solution 1
 * 
 * Brian Kernighan's Algorithm
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution1(int n) {
    int count = 0;
    
    while (n > 0) {
        n = n & (n - 1);
        count++;
    }
    
    return count;
}

/**
 * Solution 2
 * 
 * Shift & Mask
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution2(int n) {
    int count = 0;
    
    while (n > 0) {
        count += (n & 1);
        n >>= 1;
    }
    
    return count;
}
