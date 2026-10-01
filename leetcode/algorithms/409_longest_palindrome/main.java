import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class LongestPalindrome {
    /**
     * Map
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int longestPalindrome(String s) {
        int result = 0;
        Map<Character, Integer> sMap = new HashMap<>();

        for (char c : s.toCharArray()) {
            if (sMap.get(c) == null) {
                sMap.put(c, 1);
            } else {
                result += 2;
                sMap.remove(c);
            }
        }

        if (!sMap.isEmpty()) {
            result++;
        }

        return result;
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
    public int solution1(String s) {
        int[] count = new int[128];

        for (int i = 0; i < s.length(); i++) {
            count[s.charAt(i)]++;
        }

        int length = 0;
        boolean hasOdd = false;
        for (int c : count) {
            length += c / 2 * 2;

            if (c % 2 == 1) {
                hasOdd = true;
            }
        }

        return hasOdd ? length + 1 : length;
    }

    /**
     * Solution 2
     * 
     * Set Toggle
     *
     * Complexities:
     *   N - The Size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int solution2(String s) {
        Set<Character> set = new HashSet<>();
        int length = 0;

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);

            if (!set.add(c)) {
                set.remove(c);
                length += 2;
            }
        }

        return set.isEmpty() ? length : length + 1;
    }
}
