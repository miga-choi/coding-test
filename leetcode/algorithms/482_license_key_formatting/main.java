class LicenseKeyFormatting {
    /**
     * Reverse Chunking (Substring Prepend)
     *
     * Complexities:
     *   N - The Size of `s`
     *   G - `N` / `k`
     *   - Time Complexity: O(N * G)
     *   - Space Complexity: O(N)
     */
    public String licenseKeyFormatting(String s, int k) {
        s = s.replaceAll("-", "").toUpperCase();
        String result = "";

        for (int i = s.length(); i >= 0; i -= k) {
            if (i > k) {
                result = "-" + s.substring(i - k, i) + result;
            } else {
                result = s.substring(0, i) + result;
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     *
     * Reverse Traversal
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public String solution1(String s, int k) {
        StringBuilder sb = new StringBuilder();
        int count = 0;

        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == '-') {
                continue;
            }

            if (count == k) {
                sb.append('-');
                count = 0;
            }

            sb.append(Character.toUpperCase(c));
            count++;
        }

        return sb.reverse().toString();
    }

    /**
     * Solution 2
     *
     * Two-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public String solution2(String s, int k) {
        int alnum = 0;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) != '-') {
                alnum++;
            }
        }

        if (alnum == 0) {
            return "";
        }

        int dashes = (alnum - 1) / k;
        char[] result = new char[alnum + dashes];

        int w = result.length - 1, count = 0;
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s.charAt(i);
            if (c == '-') {
                continue;
            }

            if (count == k) {
                result[w--] = '-';
                count = 0;
            }

            result[w--] = Character.toUpperCase(c);
            count++;
        }

        return new String(result);
    }
}
