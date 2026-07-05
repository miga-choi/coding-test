class PowerOfTwo {
public:
    /**
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    bool isPowerOfTwo(int n) {
        if (n <= 0) {
            return false;
        }

        while (n / 2) {
            if (n > 1 && (n % 2)) {
                return false;
            }
            n /= 2;
        }

        return true;
    }


    // Solution
    /**
     * Bit Manipulation
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    bool solution(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }
};
