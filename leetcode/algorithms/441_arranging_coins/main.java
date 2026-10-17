class ArrangingCoins {
    /**
     * Complexities:
     *   N - `n`
     *   - Time Complexity: O(√N)
     *   - Space Complexity: O(1)
     */
    public int arrangeCoins(int n) {
        for (int i = 1; i > 0; i++) {
            n -= i;

            if (n == 0) {
                return i;
            } else if (n < 0) {
                return i - 1;
            }
        }

        return 0;
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
    public int solution1(int n) {
        int row = 1;

        while (n >= row) {
            n -= row;
            row++;
        }

        return row - 1;
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
    public int solution2(int n) {
        int left = 1, right = n;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long coins = (long) mid * (mid + 1) / 2;

            if (coins == n) {
                return mid;
            } else if (coins < n) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return right;
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
    public int solution3(int n) {
        return (int) ((Math.sqrt(1 + 8.0 * n) - 1) / 2);
    }
}
