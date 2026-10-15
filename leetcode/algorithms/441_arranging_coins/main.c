#include <math.h> // sqrt

/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
int arrangeCoins(int n) {
  int level = 0;

  while (n - level > 0) {
    level++;
    n -= level;
  }

  return level;
}


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
int solution1(int n) {
    int k = 0;

    while (n > k) {
        k++;
        n -= k;
    }

    return k;
}

/**
 * Solution 2
 * 
 * Binary Search
 * 
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
int solution2(int n) {
    long long lo = 0, hi = n;

    while (lo < hi) {
        long long mid = lo + (hi - lo + 1) / 2;

        if (mid * (mid + 1) / 2 <= n) {
            lo = mid;
        } else {
            hi = mid - 1;
        }
    }

    return (int)lo;
}

/**
 * Solution 3
 * 
 * Quadratic Formula
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
int solution3(int n) {
    long long k = (long long)((sqrt(8.0 * n + 1) - 1) / 2);

    while (k * (k + 1) / 2 > n) {
        k--;
    }
    while ((k + 1) * (k + 2) / 2 <= n) {
        k++;
    }

    return (int)k;
}
