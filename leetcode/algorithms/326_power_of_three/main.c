#include <stdbool.h>

/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(log₃ᴺ)
 *   - Space Complexity: O(1)
 */
bool isPowerOfThree(int n) {
    if (n <= 0) {
        return false;
    }

    while (n > 1) {
        if (n % 3) {
            return false;
        }
        n /= 3;
    }

    return true;
}


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(log₃ᴺ)
 *   - Space Complexity: O(1)
 */
bool solution1(int n) {
    if (n <= 0) {
        return false;
    }

    while (n % 3 == 0) {
        n /= 3;
    }

    return n == 1;
}

/**
 * Solution 2
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
bool solution2(int n) {
    return n > 0 && 1162261467 % n == 0;
}

// Solution 3: Base Conversion
bool solution3(int n) {
    if (n < 1) {
        return false;
    }

    char* nbase3 = "";

    while (n) {
        // conversion to base 3
        nbase3 += to_string(n % 3), n /= 3;
    }

    int i = 0;

    while (i < size(nbase3) - 1) {
        // checking if all digits in base 3 converted number except first one are 0
        if (nbase3[i++] != '0') {
            return false;
        }
    }

    // check if starting digit is 1
    return nbase3[i] == '1';
}

// Solution 4: Space optimized Base Converison
bool solution4(int n) {
    if (n < 1) {
        return false;
    }
    for (; n != 1; n /= 3) {
        if (n % 3 != 0) {
            return false;
        }
    }
    return true;
}

// Solution 5: Without loops or recursion - Divisiblity Check w/ Largest power of 3
bool solution5(int n) {
    // pow(3, floor(log(INT_MAX)/log(3))) = 1162261467
    return n > 0 && 1162261467 % n == 0;
}
