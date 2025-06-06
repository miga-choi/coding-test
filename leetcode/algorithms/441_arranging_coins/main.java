class ArrangingCoins {
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
     * Optimized Bit Manipulation (With Early Exit)
     *
     * Number of bits in Int.MAX = log(Int.MAX) = 31 bits
     * Number of bits in sqrt(Int.MAX) = log(sqrt(Int.MAX)) = 16 bits.
     *
     * Thus we need to create a mask with 16 bits, where the 15th bit is set to 1 &
     * rest are set to zero.
     *
     * In this solution we are setting each bit and checking if the
     * result*(result+1)/2 is less than N,
     * else we do not set the bit in the result.
     *
     * Time Complexity: O(16) = O(1)
     *
     * Space Complexity: O(1)
     *
     * N = Input number.
     */
    public int solution1(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input Number is invalid. Only positive numbers are allowed");
        }

        int mask = 1 << 15;
        long result = 0;

        while (mask > 0) {
            long temp = result | mask;
            long coinsFilled = temp * (temp + 1) / 2;
            if (coinsFilled == n) {
                return (int) temp;
            }
            if (coinsFilled < n) {
                result = temp;
            }
            mask >>= 1;
        }

        return (int) result;
    }

    /**
     * Solution 2
     * Optimized binary search
     *
     * Time Complexity: O(log(N/2)). In case of Int.MAX, time complexity can maximum
     * be O(30) = O(1)
     *
     * Space Complexity: O(1)
     *
     * N = Input number
     */
    public int solution2(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input Number is invalid. Only positive numbers are allowed");
        }
        if (n <= 1) {
            return n;
        }
        if (n <= 3) {
            return n == 3 ? 2 : 1;
        }

        // Binary Search space will start from 2 to n/2.
        long start = 2;
        long end = n / 2;
        while (start <= end) {
            long mid = start + (end - start) / 2;
            long coinsFilled = mid * (mid + 1) / 2;
            if (coinsFilled == n) {
                return (int) mid;
            }
            if (coinsFilled < n) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }

        // Since at this point start > end, start will start pointing to a value greater
        // than the desired result. We will return end as it will point to the correct
        // int value.
        return (int) end;
    }

    /**
     * Solution 3
     * Math: Using Sum of Integers Formula
     *
     * This problem can be reduced down to:
     * (K * (K+1))/2 <= N
     * K^2 + K <= 2*N
     * (K + 1/2)^2 <= 2*N + 1/4
     * K <= sqrt(2*N + 1/4) - 1/2
     *
     * Since we want the row that has full levels, we just need to return the floor
     * of above result.
     * Thus, K = floor(sqrt(2*N + 1/4) - 1/2)
     *
     * Time Complexity: O(1)
     *
     * Space Complexity: O(1)
     */
    public int solution3(int n) {
        if (n < 0) {
            throw new IllegalArgumentException("Input Number is invalid. Only positive numbers are allowed");
        }
        return (int) (Math.sqrt(2 * (long) n + 0.25) - 0.5);
    }
}
