class PowerOfTwo {
    /**
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public boolean isPowerOfTwo(int n) {
        int m = 0;

        while (Math.pow(2, m) <= n) {
            if (Math.pow(2, m) == n) {
                return true;
            }
            m++;
        }

        return false;
    }


    // Solution
    /**
     * Solution 1
     *
     * Bit Manipulation
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public boolean solution1(int n) {
        return n > 0 && (n & (n - 1)) == 0;
    }

    /**
     * Solution 2
     *
     * Built-in Function
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public boolean solution2(int n) {
        return n > 0 && Integer.bitCount(n) == 1;
    }

    /**
     * Solution 3
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public boolean solution3(int n) {
        return n > 0 && (1073741824 % n == 0);
    }
}
