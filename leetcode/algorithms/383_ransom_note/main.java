import java.util.HashMap;
import java.util.Map;

class RansomNote {
    /**
     * HashMap
     *
     * Complexities:
     *   N - The Size of `ransomNote`
     *   M - The Size of `magazine`
     *   K - The Size of Characters in `magazine`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(K)
     */
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> magazineMap = new HashMap<>();

        for (int i = 0; i < magazine.length(); i++) {
            if (magazineMap.get(magazine.charAt(i)) != null) {
                magazineMap.put(magazine.charAt(i), magazineMap.get(magazine.charAt(i)) + 1);
            } else {
                magazineMap.put(magazine.charAt(i), 1);
            }
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            if (magazineMap.get(ransomNote.charAt(i)) != null && magazineMap.get(ransomNote.charAt(i)) > 0) {
                magazineMap.put(ransomNote.charAt(i), magazineMap.get(ransomNote.charAt(i)) - 1);
            } else {
                return false;
            }
        }

        return true;
    }


    // Solution
    /**
     * Counting Array
     *
     * Complexities:
     *   N - The Size of `ransomNote`
     *   M - The Size of `magazine`
     *   - Time Complexity: O(N + M)
     *   - Space Complexity: O(1)
     */
    public boolean solution(String ransomNote, String magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        int[] count = new int[26];

        for (int i = 0; i < magazine.length(); i++) {
            count[magazine.charAt(i) - 'a']++;
        }

        for (int i = 0; i < ransomNote.length(); i++) {
            if (--count[ransomNote.charAt(i) - 'a'] < 0) {
                return false;
            }
        }

        return true;
    }
}
