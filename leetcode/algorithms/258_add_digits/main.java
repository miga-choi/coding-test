class AddDigits {
    /**
     * Iterative
     *
     * Complexities:
     *   - Time Complexity: O(log₁₀ᴺ)
     *   - Space Complexity: O(1)
     */
    public int addDigits(int num) {
        String numString = String.valueOf(num);

        while (numString.length() > 1) {
            num = 0;

            for (int i = 0; i < numString.length(); i++) {
                num += Integer.parseInt(String.valueOf(numString.charAt(i)));
            }

            numString = String.valueOf(num);
        }

        return num;
    }


    // Solution
    /**
     * Solution 1
     *
     * Digital Root
     *
     * Complexities:
     *   - Time Complexity: O(1)
     *   - Space Complexity: O(1)
     */
    public int solution1(int num) {
        if (num == 0) {
            return 0;
        }

        return (num - 1) % 9 + 1;
    }

    /**
     * Solution 2
     *
     * Iterative
     *
     * Complexities:
     *   - Time Complexity: O(log₁₀ᴺ)
     *   - Space Complexity: O(1)
     */
    public int solution2(int num) {
        while (num >= 10) {
            int sum = 0;

            while (num > 0) {
                sum += num % 10;
                num /= 10;
            }

            num = sum;
        }

        return num;
    }
}
