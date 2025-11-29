import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class LongestSubstringWithoutRepeatingCharacters {
    /**
     * Sliding Window
     *
     * Complexities:
     *   N - Length of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public int lengthOfLongestSubstring(String s) {
        int[] charmap = new int[128];
        Arrays.fill(charmap, -1);

        int left = 0;
        int maxLength = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);

            if (charmap[currentChar] >= left) {
                left = charmap[currentChar] + 1;
            }

            charmap[currentChar] = right;

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }


    // Solution
    /**
     * Sliding Window (using Map)
     *
     * Complexities:
     *   N - Length of `s`
     *   M - Length of Available Characters in `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(Min(M, N))
     */
    public int solution(String s) {
        Map<Character, Integer> map = new HashMap<>();

        int maxLength = 0;
        int left = 0;

        for (int right = 0; right < s.length(); right++) {
            char currentChar = s.charAt(right);

            if (map.containsKey(currentChar)) {
                left = Math.max(left, map.get(currentChar) + 1);
            }

            map.put(currentChar, right);

            maxLength = Math.max(maxLength, right - left + 1);
        }

        return maxLength;
    }
}
