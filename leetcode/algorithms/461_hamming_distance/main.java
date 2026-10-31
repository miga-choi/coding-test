class HammingDistance {
    /**
     * Math
     *
     * Complexities:
     *   M - `x`
     *   N - `y`
     *   - Time Complexity: O(logᵐᵃˣ⁽ᴹ˒ᴺ⁾)
     *   - Space Complexity: O(1)
     */
    public int hammingDistance(int x, int y) {
        return Integer.toString(x ^ y, 2).replaceAll("0", "").length();
    }


    // Solution
    /**
     * Solution 1
     *
     * Bit Manipulation (XOR + Brian Kernighan)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public int solution1(int x, int y) {
        int xor = x ^ y;
        int count = 0;

        while (xor != 0) {
            xor &= xor - 1;
            count++;
        }

        return count;
    }

    /**
     * Solution 2
     *
     * Bit Manipulation (Built-in)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public int solution2(int x, int y) {
        return Integer.bitCount(x ^ y);
    }

    /**
     * Solution 3
     *
     * Bit Manipulation (Shift & Mask)
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public int solution3(int x, int y) {
        int xor = x ^ y;
        int count = 0;

        for (int i = 0; i < 32; i++) {
            count += (xor >>> i) & 1;
        }

        return count;
    }
}
