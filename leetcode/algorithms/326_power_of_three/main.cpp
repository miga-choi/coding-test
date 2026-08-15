class PowerOfThree {
public:
    /**
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(log₃ᴺ)
     *   - Space Complexity: O(1)
     */
    bool isPowerOfThree(int n) {
        if (n < 1) {
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
};
