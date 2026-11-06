class NumberComplement {
    /**
     * String Conversion (Binary String Flip)
     *
     * Complexities:
     *   N - The Bit Length of 'num'
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    public int findComplement(int num) {
        String[] binary = Integer.toBinaryString(num).split("");
        String result = "";

        for (String b : binary) {
            if (b.equals("1")) {
                result += "0";
            } else {
                result += "1";
            }
        }

        return Integer.parseInt(result, 2);
    }


    // Solution
    /**
     * Solution 1
     *
     * Bit Manipulation (Mask + XOR)
     *
     * Complexities:
     *   N - The Bit Length of 'num'
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public int solution1(int num) {
        long mask = 1;

        while (mask <= num) {
            mask <<= 1;
        }

        return (int) (mask - 1) ^ num;
    }

    /**
     * Solution 2
     *
     * Bit Manipulation (Highest Bit Propagation)
     *
     * Complexities:
     *   N - The Bit Length of 'num'
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public int solution2(int num) {
        int mask = num;
        mask |= mask >>> 1;
        mask |= mask >>> 2;
        mask |= mask >>> 4;
        mask |= mask >>> 8;
        mask |= mask >>> 16;
        return mask ^ num;
    }

    /**
     * Solution 3
     *
     * Bit Manipulation (Built-in Bit Length)
     *
     * Complexities:
     *   N - The Bit Length of 'num'
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public int solution3(int num) {
        int bits = 32 - Integer.numberOfLeadingZeros(num);
        return (int) ((1L << bits) - 1) ^ num;
    }
}
