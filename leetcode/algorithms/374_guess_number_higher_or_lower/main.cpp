#include <numeric>   // std::midpoint
using namespace std;

class GuessNumberHigherOrLower {
public:
    /**
     * Forward declaration of guess API.
     * @param  num   your guess
     * @return 	     -1 if num is higher than the picked number
     *			      1 if num is lower than the picked number
     *               otherwise return 0
     * int guess(int num);
     */
    int guess(int num);

    /**
     * Binary Search
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int guessNumber(int n) {
        int low = 1;
        int high = n;
        int mid;

        while (low <= high) {
            mid = (high - low) / 2 + low;
            if (guess(mid) == -1) {
                high = mid - 1;
            } else if (guess(mid) == 1) {
                low = mid + 1;
            } else {
                break;
            }
        }

        return mid;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Binary Search
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int solution1(int n) {
        int lo = 1, hi = n;

        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            int r = guess(mid);

            if (r == 0) {
                return mid;
            } else if (r < 0) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     * 
     * Binary Search + std::midpoint (C++20)
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    int solution2(int n) {
        int lo = 1, hi = n;

        while (lo <= hi) {
            int mid = midpoint(lo, hi);
            int r = guess(mid);

            if (r == 0) {
                return mid;
            } else if (r < 0) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return -1;
    }

    /**
     * Solution 3
     * 
     * Recursion
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    int helper(int lo, int hi) {
        if (lo > hi) {
            return -1;
        }

        int mid = lo + (hi - lo) / 2;
        int r = guess(mid);

        if (r == 0) {
            return mid;
        } else if (r < 0) {
            return helper(lo, mid - 1);
        } else {
            return helper(mid + 1, hi);
        }
    }

    int solution3(int n) {
        return helper(1, n);
    }
};
