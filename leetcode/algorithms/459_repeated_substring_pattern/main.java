class RepeatedSubstringPattern {
    /**
     * String Concatenation
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N) ~ O(N²)
     *   - Space Complexity: O(N)
     */
    public boolean repeatedSubstringPattern(String s) {
        return s.substring(1).concat(s.substring(0, s.length() - 1)).contains(s);
    }


    // Solution
    /**
     * Solution 1
     * 
     * Divisor Enumeration
     *
     * Complexities:
     *   N - The Size of `s`
     *   d(N) - The Number of Divisors of N
     *   - Time Complexity: O(N * d(N))
     *   - Space Complexity: O(1)
     */
    public boolean solution1(String s) {
        int n = s.length();

        for (int len = 1; len <= n / 2; len++) {
            if (n % len != 0) {
                continue;
            }

            boolean match = true;
            for (int i = len; i < n; i++) {
                if (s.charAt(i) != s.charAt(i - len)) {
                    match = false;
                    break;
                }
            }

            if (match) {
                return true;
            }
        }

        return false;
    }

    /**
     * Solution 2
     * 
     * String Concatenation
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N) ~ O(N²)
     *   - Space Complexity: O(N)
     */
    public boolean solution2(String s) {
        String doubled = s + s;
        return doubled.substring(1, doubled.length() - 1).contains(s);
    }

    /**
     * Solution 3
     * 
     * KMP Failure Function
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean solution3(String s) {
        int n = s.length();
        int[] lps = new int[n];

        for (int i = 1, len = 0; i < n;) {
            if (s.charAt(i) == s.charAt(len)) {
                lps[i++] = ++len;
            } else if (len > 0) {
                len = lps[len - 1];
            } else {
                lps[i++] = 0;
            }
        }

        int period = n - lps[n - 1];
        return period < n && n % period == 0;
    }
}
