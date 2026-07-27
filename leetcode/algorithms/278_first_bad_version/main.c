#include <stdbool.h>

// The API isBadVersion is defined for you.
bool isBadVersion(int version);

/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int firstBadVersion(int n) {
    int low = 1;
    int high = n;
    int mid;

    while (low < high) {
        mid = low + ((high - low) / 2);

        if (isBadVersion(mid)) {
            high = mid;
        } else {
            low = mid + 1;
        }
    }

    return low;
}


// Solution
/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int solution(int n) {
    int left = 1;
    int right = n;

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (isBadVersion(mid)) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}
