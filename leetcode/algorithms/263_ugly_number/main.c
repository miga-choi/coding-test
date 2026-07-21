#include <stdbool.h>

/**
 * Iterative Division
 * 
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(N)
 */
bool isUgly(int n) {
    while (n > 0) {
        if (n % 5 == 0) {
            n /= 5;
        } else if (n % 3 == 0) {
            n /= 3;
        } else if (n % 2 == 0) {
            n /= 2;
        } else {
            if (n == 0 || n == 1 || n == 2 || n == 3 || n == 5) {
                return true;
            } else {
                break;
            }
        }
    }
    return false;
}


// Solution
/**
 * Iterative Division
 * 
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(N)
 */
bool solution(int n) {
    if (n <= 0) {
        return false;
    }

    while (n % 2 == 0) {
        n /= 2;
    }
    while (n % 3 == 0) {
        n /= 3;
    }
    while (n % 5 == 0) {
        n /= 5;
    }

    return n == 1;
}
