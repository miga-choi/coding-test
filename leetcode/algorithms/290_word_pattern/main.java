import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class WordPattern {
    /**
     * Complexities:
     *   N - The size of `pattern`
     *   M - The size of `s`
     *   - Time Complexity: O(N * M)
     *   - Space Complexity: O(N + M)
     */
    public boolean wordPattern(String pattern, String s) {
        String[] sArray = s.split(" ");

        if (sArray.length != pattern.length()) {
            return false;
        }

        Map<Character, String> sMap = new HashMap<>();

        for (int i = 0; i < sArray.length; i++) {
            if (sMap.get(pattern.charAt(i)) == null) {
                if (sMap.containsValue(sArray[i])) {
                    return false;
                }
                sMap.put(pattern.charAt(i), sArray[i]);
            } else {
                if (!sMap.get(pattern.charAt(i)).equals(sArray[i])) {
                    return false;
                }
            }

        }

        return true;
    }


    // Solution
    /**
     * Complexities:
     *   N - The number of characters' length in `s`
     *   - Time Complexity: O(N)
     *   - Space Complexity: O(N)
     */
    public boolean solution(String pattern, String s) {
        String[] words = s.split(" ");

        if (pattern.length() != words.length) {
            return false;
        }

        Map<Character, String> charToWord = new HashMap<>();
        Set<String> usedWords = new HashSet<>();

        for (int i = 0; i < pattern.length(); i++) {
            char ch = pattern.charAt(i);
            String word = words[i];

            if (charToWord.containsKey(ch)) {
                if (!charToWord.get(ch).equals(word)) {
                    return false;
                }
            } else {
                if (usedWords.contains(word)) {
                    return false;
                }

                charToWord.put(ch, word);
                usedWords.add(word);
            }
        }

        return true;
    }
}
