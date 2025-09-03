import java.util.Arrays;

class ValidAnagram {
    /**
     * Frequency Counter
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
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
     * Sorting
     * - Time Complexity: O(N * logᴺ)
     * - Space Complexity: O(N)
     */
    public boolean solution1(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        char[] sChars = s.toCharArray();
        char[] tChars = t.toCharArray();

        Arrays.sort(sChars);
        Arrays.sort(tChars);

        return Arrays.equals(sChars, tChars);
    }

    /**
     * Solution 2
     * 
     * Frequency Counting
     * - Time Complexity: O(N)
     * - Space Complexity: O(1)
     */
    public boolean solution2(String s, String t) {
        if (s.length() != t.length()) {
            return false;
        }

        int[] charCounts = new int[26];

        for (int i = 0; i < s.length(); i++) {
            charCounts[s.charAt(i) - 'a']++;
        }

        for (int i = 0; i < t.length(); i++) {
            charCounts[t.charAt(i) - 'a']--;
            if (charCounts[t.charAt(i) - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
}
