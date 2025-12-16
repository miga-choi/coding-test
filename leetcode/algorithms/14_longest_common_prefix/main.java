import java.util.Arrays;

class LongestCommonPrefix {
    /**
     * Complexities:
     *   S = N * L
     *   N - `strsSize`
     *   L - Length of Shortest `str` in `strs
     *   - Time Complexity: O(S)
     *   - Space Complexity: O(1)
     */
    public String longestCommonPrefix(String[] strs) {
        String result = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            int count = 0;
            for (String str : strs) {
                if (i > str.length() - 1 || str.charAt(i) != c) {
                    return result;
                }
                count++;
                if (count == strs.length) {
                    result += c;
                }
            }
        }

        return result;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Horizontal Scanning
     * 
     * Complexities:
     *   S - Quantity of characters in `strs`
     *   - Time Complexity: O(S)
     *   - Space Complexity: O(1)
     */
    public String solution1(String[] strs) {
        String prefix = strs[0];

        for (int i = 1; i < strs.length; i++) {
            while (strs[i].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);

                if (prefix.isEmpty()) {
                    return "";
                }
            }
        }

        return prefix;
    }

    /**
     * Solution 2
     * 
     * Sorting
     *
     * Complexities:
     *   N - Length of `strs`
     *   L - Length of Longest `str` in `strs`
     *   - Time Complexity: O(N * L * logᴺ)
     *   - Space Complexity: O(logᴺ)
     */
    public String solution2(String[] strs) {
        Arrays.sort(strs);
        
        String s1 = strs[0];
        String s2 = strs[strs.length - 1];
        
        int idx = 0;

        while (idx < s1.length() && idx < s2.length()) {
            if (s1.charAt(idx) == s2.charAt(idx)) {
                idx++;
            } else {
                break;
            }
        }
        
        return s1.substring(0, idx);
    }
}
