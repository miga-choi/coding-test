class ValidPerfectSquare {
    /**
     * Complexities:
     *   N - `num`
     *   - Time Complexity: O(√N)
     *   - Space Complexity: O(1)
     */
    public boolean isPerfectSquare(int num) {
        int i = 0;

        while (true) {
            if (Math.pow(i, 2) == num) {
                return true;
            } else if (Math.pow(i, 2) > num) {
                return false;
            } else {
                i++;
            }
        }
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
    public boolean solution1(int num) {
        int left = 1, right = num;

        while (left <= right) {
            int mid = left + (right - left) / 2;
            long square = (long) mid * mid;

            if (square == num) {
                return true;
            } else if (square < num) {
                left = mid + 1;
            } else {
                right = mid - 1;
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
    public boolean solution2(int num) {
        int odd = 1;

        while (num > 0) {
            num -= odd;
            odd += 2;
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
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public boolean solution3(int num) {
        long x = num;

        while (x * x > num) {
            x = (x + num / x) / 2;
        }

        return x * x == num;
    }
}
