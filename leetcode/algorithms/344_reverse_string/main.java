class ReverseString {
    /**
     * Two pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    public void reverseString(char[] s) {
        for (int i = 0; i < s.length / 2; i++) {
            char temp = s[i];
            s[i] = s[s.length - 1 - i];
            s[s.length - 1 - i] = temp;
        }
    }


    // Solution
    /**
     * Solution 1
     *
     * Two pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    public void solution1(char[] s) {
        int left = 0, right = s.length - 1;

        while (left < right) {
            char tmp = s[left];
            s[left] = s[right];
            s[right] = tmp;
            left++;
            right--;
        }
    }

    /**
     * Solution 2
     *
     * Two pointers
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(1)
     */
    public void solution2(char[] s) {
        for (int i = 0, j = s.length - 1; i < j; i++, j--) {
            char tmp = s[i];
            s[i] = s[j];
            s[j] = tmp;
        }
    }

    /**
     * Solution 3
     *
     * Recursion
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexities: O(N)
     *   - Space Complexities: O(N)
     */
    public void solution3(char[] s) {
        helper(s, 0, s.length - 1);
    }

    private void helper(char[] s, int left, int right) {
        if (left >= right) {
            return;
        }

        char tmp = s[left];
        s[left] = s[right];
        s[right] = tmp;
        helper(s, left + 1, right - 1);
    }
}
