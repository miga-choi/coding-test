#include <cmath>   // std::sqrt
#include <numeric> // std::midpoint
using namespace std;

class ValidPerfectSquare {
public:
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
     * Sum of Odd Numbers
     *
     * Complexities:
     *   N - `num`
     *   - Time Complexity: O(√N)
     *   - Space Complexity: O(1)
     */
    bool solution2(int num) {
        for (int odd = 1; num > 0; odd += 2) {
            num -= odd;
        }

        return num == 0;
    }

    /**
     * Solution 3
     *
     * Newton-Raphson Method
     *
     * Complexities:
     *   N - `num`
     *   - Time Complexity: O(log(logᴺ))
     *   - Space Complexity: O(1)
     */
    bool solution3(int num) {
        long long x = num;

        while (x * x > num) {
            x = (x + num / x) / 2;
        }

        return x * x == num;
    }

    /**
     * Solution 4
     *
     * Binary Search + std::midpoint
     *
     * Complexities:
     *   N - `num`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    bool solution4(int num) {
        long long lo = 1, hi = num;

        while (lo <= hi) {
            long long mid = midpoint(lo, hi);
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
     * Solution 5
     *
     * std::sqrt
     *
     * Complexities:
     *   N - `num`
     *   - Time Complexity: O(log(logᴺ))
     *   - Space Complexity: O(1)
     */
    bool solution5(int num) {
        long long r = static_cast<long long>(sqrt(static_cast<double>(num)));

        return r * r == num || (r + 1) * (r + 1) == num;
    }
};
