#include <stdbool.h>

/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
bool canWinNim(int n) {
    return n % 4;
}


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
bool solution1(int n) {
    return n % 4;
}

/**
 * Solution 2
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
bool solution2(int n) {
    return (n & 3) != 0;
}