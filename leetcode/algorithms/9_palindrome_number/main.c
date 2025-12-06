#include <stdbool.h>

/**
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
bool isPalindrome(int x) {
    if (x < 0) {
        return false;
    }

    long origin = (long)x;
    long sum = 0;

    while (x > 0) {
        long res = (long)x % 10;
        x /= 10;
        sum = sum * 10 + res;
    }

    return sum == origin;
}


// Solution
/**
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
bool solution(int x) {
    if (x < 0) {
        return false;
    }

    long long reversed = 0;
    int temp = x;

    while (temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }

    return (x == reversed);
}
