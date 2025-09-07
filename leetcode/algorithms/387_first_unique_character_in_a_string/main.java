import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class FirstUniqueCharacterInAString {
    /**
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
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
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    public int solution1(String s) {
        int[] counts = new int[26];

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            counts[c - 'a']++;
        }

        for (int i = 0; i < s.length(); i++) {
            char c = s.charAt(i);
            if (counts[c - 'a'] == 1) {
                return i;
            }
        }

        return -1;
    }

    /**
     * Solution 2
     * 
     * Hash table
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    public int solution2(String s) {
        Map<Character, Integer> counts = new HashMap<>();

        for (char c : s.toCharArray()) {
            counts.put(c, counts.getOrDefault(c, 0) + 1);
        }

        for (int i = 0; i < s.length(); i++) {
            if (counts.get(s.charAt(i)) == 1) {
                return i;
            }
        }

        return -1;
    }
}
