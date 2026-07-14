import java.util.Arrays;
import java.util.HashMap;
import java.util.Map;

class ValidAnagram {
    /**
     * Frequency Counting
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public boolean isAnagram(String s, String t) {
        int len = s.length();

        if (len != t.length()) {
            return false;
        }

        int[] alphabetNumArray = new int[26];
        Arrays.fill(alphabetNumArray, 0);

        for (int i = 0; i < len; i++) {
            alphabetNumArray[s.charAt(i) - 'a']++;
            alphabetNumArray[t.charAt(i) - 'a']--;
        }

        for (int i = 0; i < 26; i++) {
            if (alphabetNumArray[i] != 0) {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Solution 1
     * 
     * Frequency Counting
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(1)
     */
    public boolean solution1(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] charCounts = new int[26];

        for (int i = 0; i < s.length(); i++) {
            charCounts[s.charAt(i) - 'a']++;
            charCounts[t.charAt(i) - 'a']--;
        }

        for (int count : charCounts) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }

    /**
     * Solution 2
     * 
     * HashMap + Unicode
     *
     * Complexities:
     *   N - The size of `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean solution2(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        Map<Character, Integer> map = new HashMap<>();

        for (int i = 0; i < s.length(); i++) {
            char charS = s.charAt(i);
            char charT = t.charAt(i);
            
            map.put(charS, map.getOrDefault(charS, 0) + 1);
            map.put(charT, map.getOrDefault(charT, 0) - 1);
        }

        for (int count : map.values()) {
            if (count != 0) {
                return false;
            }
        }

        return true;
    }
}
