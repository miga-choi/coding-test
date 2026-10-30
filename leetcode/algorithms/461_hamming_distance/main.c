/**
 * Math
 * 
 * Complexities:
 *   M - `x`
 *   N - `y`
 *   - Time Complexity: O(logᵐᵃˣ⁽ᴹ˒ᴺ⁾)
 *   - Space Complexity: O(1)
 */
int hammingDistance(int x, int y) {
    int cnt = 0;

    while (x || y) {
        if (x % 2 != y % 2) {
            cnt++;
        }

        x /= 2;
        y /= 2;
    }

    return cnt;
}


// Solution
/**
 * Solution 1
 * 
 * Bit Manipulation (XOR + Bit-by-bit Shift)
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution1(int x, int y) {
    unsigned int d = (unsigned int)(x ^ y);
    int count = 0;

    while (d != 0) {
        count += d & 1;
        d >>= 1;
    }

    return count;
}

/**
 * Solution 2
 * 
 * Bit Manipulation (XOR + Brian Kernighan’s Algorithm)
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution2(int x, int y) {
    unsigned int d = (unsigned int)(x ^ y);
    int count = 0;

    while (d != 0) {
        d &= d - 1;
        count++;
    }

    return count;
}

/**
 * Solution 3
 * 
 * Built-in Popcount
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution3(int x, int y) {
    return __builtin_popcount((unsigned int)(x ^ y));
}
