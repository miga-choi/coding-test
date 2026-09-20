class IsSubsequence {
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - The Size of `s`
     *   M - The Size of `t`
     *   - Time Complexity: O(M)
     *   - Space Complexity: O(1)
     */
    public boolean isSubsequence(String s, String t) {
        while (s.length() > 0) {
            int index = t.indexOf(s.charAt(0));

            if (index == -1) {
                return false;
            }

            t = t.substring(index + 1);
            s = s.substring(1, s.length());
        }

        return true;
    }


    // Solution
    /**
     * Two Pointers
     *
     * Complexities:
     *   N - The Size of `s`
     *   M - The Size of `t`
     *   - Time Complexity: O(M)
     *   - Space Complexity: O(1)
     */
    public boolean solution(String s, String t) {
        int i = 0, j = 0;

        while (i < s.length() && j < t.length()) {
            if (s.charAt(i) == t.charAt(j)) {
                i++;
            }

            j++;
        }

        return i == s.length();
    }
}
