import java.util.HashMap;
import java.util.Map;

class RansomNote {
    public boolean canConstruct(String ransomNote, String magazine) {
        Map<Character, Integer> magazineMap = new HashMap<Character, Integer>();

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
    public boolean solution(String ransomNote, String magazine) {
        if (ransomNote.length() > magazine.length()) {
            return false;
        }

        int[] alphabets_counter = new int[26];

        for (char c : magazine.toCharArray()) {
            alphabets_counter[c - 'a']++;
        }

        for (char c : ransomNote.toCharArray()) {
            if (alphabets_counter[c - 'a'] == 0) {
                return false;
            }
            alphabets_counter[c - 'a']--;
        }

        return true;
    }
}
