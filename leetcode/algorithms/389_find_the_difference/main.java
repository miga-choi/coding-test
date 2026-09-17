class FindTheDifference {
    /**
     * replaceFirst()
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(N)
     */
    public char findTheDifference(String s, String t) {
        for (int i = 0; i < s.length(); i++) {
            t = t.replaceFirst(String.valueOf(s.charAt(i)), "");
        }

        return t.charAt(0);
    }


    // Solution
    /**
     * Solution 1
     *
     * Counting Array
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public char solution1(String s, String t) {
        int[] count = new int[26];

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            if (--count[t.charAt(i) - 'a'] < 0) {
                return t.charAt(i);
            }
        }

        return ' ';
    }

    /**
     * Solution 2
     *
     * XOR
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public char solution2(String s, String t) {
        char result = t.charAt(t.length() - 1);

        for (int i = 0; i < s.length(); i++) {
            result ^= s.charAt(i) ^ t.charAt(i);
        }

        return result;
    }

    /**
     * Solution 3
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public char solution3(String s, String t) {
        int sum = 0;

        for (int i = 0; i < s.length(); i++) {
            sum -= s.charAt(i);
        }
        for (int i = 0; i < t.length(); i++) {
            sum += t.charAt(i);
        }

        return (char) sum;
    }
}
