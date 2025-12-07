class PalindromeNumber {
    /**
     * Complexities:
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean isPalindrome(int x) {
        String[] xArray = String.valueOf(x).split("");

        for (int i = 0; i < xArray.length / 2; i++) {
            if (!xArray[i].equals(xArray[xArray.length - i - 1])) {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Complexities:
     *   - Time Complexity: O(logᴺ)
     *   - Space Complexity: O(1)
     */
    public boolean solution(int x) {
        if (x < 0 || (x % 10 == 0 && x != 0)) {
            return false;
        }

        int reversedHalf = 0;

        while (x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }

        return x == reversedHalf || x == reversedHalf / 10;
    }
}
