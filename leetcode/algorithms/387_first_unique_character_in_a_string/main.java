import java.util.Arrays;

class FirstUniqueCharacterInAString {
    /**
     * Counting Array + Two-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int firstUniqChar(String s) {
        int[] alphabetNumArray = new int[26];
        Arrays.fill(alphabetNumArray, 0);

        for (char c : s.toCharArray()) {
            alphabetNumArray[(int) c - 97]++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (alphabetNumArray[(int) s.charAt(i) - 97] == 1) {
                return i;
            }
        }

        return -1;
    }


    // Solution
    /**
     * Solution 1
     *
     * Counting Array + Two-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution1(String s) {
        int[] count = new int[26];

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            if (count[s.charAt(i) - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     *
     * Counting Array + Indexing + 1.5-Pass
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution2(String s) {
        int[] idx = new int[26];
        Arrays.fill(idx, -1);

        for (int i = 0; i < s.length(); i++) {
            int c = s.charAt(i) - 'a';
            idx[c] = (idx[c] == -1) ? i : -2;
        }

        int ans = Integer.MAX_VALUE;
        for (int v : idx) {
            if (v >= 0) {
                ans = Math.min(ans, v);
            }
        }

        return ans == Integer.MAX_VALUE ? -1 : ans;
    }

    /**
     * Solution 3
     *
     * indexOf() + lastIndexOf()
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N²)
     *   - Space Complexity: O(1)
     */
    public int solution3(String s) {
        int min = Integer.MAX_VALUE;

        for (char c = 'a'; c <= 'z'; c++) {
            int first = s.indexOf(c);
            if (first != -1 && first == s.lastIndexOf(c)) {
                min = Math.min(min, first);
            }
        }

        return min == Integer.MAX_VALUE ? -1 : min;
    }
}
