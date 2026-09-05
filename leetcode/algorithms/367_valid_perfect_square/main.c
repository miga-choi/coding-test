#include <math.h>    // sqrt
#include <stdbool.h> // bool

/**
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
bool isPerfectSquare(int num) {
    if (num > 1) {
        for (long i = 0; i < num; i++) {
            if (i * i == num) {
                break;
            } else if (i * i > num) {
                return false;
            }
        }
    }

    return true;
}


// Solution
/**
 * Solution 1
 * 
 * Binary Search
 * 
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
bool solution1(int num) {
    long long lo = 1, hi = num;

    while (lo <= hi) {
        long long mid = lo + (hi - lo) / 2;
        long long sq = mid * mid;

        if (sq == num) {
            return true;
        } else if (sq < num) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}

/**
 * Solution 2
 * 
 * Binary Search
 * 
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
bool solution2(int num) {
    int lo = 1, hi = num;

    while (lo <= hi) {
        int mid = lo + (hi - lo) / 2;

        if (mid == num / mid && num % mid == 0) {
            return true;
        } else if (mid < num / mid) {
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    return false;
}

/**
 * Solution 3
 * 
 * Sum of Odd Numbers
 * 
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(√N)
 *   - Space Complexity: O(1)
 */
bool solution3(int num) {
    for (int odd = 1; num > 0; odd += 2) {
        num -= odd;
    }

    return num == 0;
}

/**
 * Solution 4
 * 
 * Newton-Raphson Method
 * 
 * Complexities:
 *   N - `num`
 *   - Time Complexity: O(log(logᴺ))
 *   - Space Complexity: O(1)
 */
bool solution4(int num) {
    long long x = num;

    while (x * x > num) {
        x = (x + num / x) / 2;
    }

    return x * x == num;
}

/**
 * Solution 5
 * 
 * sqrt
 * 
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
bool solution5(int num) {
    int r = (int)sqrt((double)num);

    return r * r == num || (r + 1) * (r + 1) == num;
}
