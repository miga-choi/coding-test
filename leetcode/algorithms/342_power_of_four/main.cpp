#include <bit> // std::has_single_bit, std::countr_zero
using namespace std;

class PowerOfFour {
public:
    /**
     * Repeated Division
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(log₄ᴺ)
     *   - Space Complexity: O(1)
     */
    bool isPowerOfFour(int n) {
        while (n > 1) {
            if (n % 4) {
                return false;
            }

            n /= 4;
        }

        return n == 1;
    }


    // Solution
    /**
     * Solution 1
     *
     * Repeated Division
     *
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(log₄ᴺ)
     *   - Space Complexity: O(1)
     */
    bool solution1(int n) {
        if (n <= 0) {
            return false;
        }

        while (n % 4 == 0) {
            n /= 4;
        }

        return n == 1;
    }

    /**
     * Solution 2
     *
     * Bit Trick
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    bool solution2(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n & 0x55555555) != 0;
    }

    /**
     * Solution 3
     *
     * Remaining 3
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    bool solution3(int n) {
        return n > 0 && (n & (n - 1)) == 0 && (n - 1) % 3 == 0;
    }

    /**
     * Solution 4
     *
     * Built-in function (C++20)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    bool solution4(int n) {
        if (n <= 0) {
            return false;
        }

        unsigned u = static_cast<unsigned>(n);

        return has_single_bit(u) && countr_zero(u) % 2 == 0;
    }
};
