class UglyNumber {
    /**
     * Iterative Division
     *
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(N)
     */
    public boolean isUgly(int n) {
        if (n < 1) {
            return false;
        }

        while (n > 1) {
            if (n % 5 == 0) {
                n /= 5;
            } else if (n % 3 == 0) {
                n /= 3;
            } else if (n % 2 == 0) {
                n /= 2;
            } else {

                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Iterative Division
     *
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(N)
     */
    public boolean solution(int n) {
        if (n <= 0) {
            return false;
        }

        int[] factors = { 2, 3, 5 };
        for (int factor : factors) {
            while (n % factor == 0) {
                n /= factor;
            }
        }

        return n == 1;
    }
}
