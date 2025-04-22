import java.util.HashMap;
import java.util.Map;

class ValidAnagram {
    public boolean isAnagram(String s, String t) {
        Map<Character, Integer> sMap = new HashMap<Character, Integer>();

        for (char c_ : s.toCharArray()) {
            if (sMap.get(c_) == null) {
                sMap.put(c_, 1);
            } else {
                sMap.put(c_, sMap.get(c_) + 1);
            }
        }

        for (char c_ : t.toCharArray()) {
            if (sMap.get(c_) != null && sMap.get(c_) > 0) {
                sMap.put(c_, sMap.get(c_) - 1);
            } else {
                return false;
            }
        }

        for (Integer v_ : sMap.values()) {
            if (v_ > 0) {
                return false;
            }
        }

        return true;
    }

    
    // Solution
    public boolean solution(String s, String t) {
        int[] alphabet = new int[26];
        for (int i = 0; i < s.length(); i++) {
            alphabet[s.charAt(i) - 'a']++;
        }
        for (int i = 0; i < t.length(); i++) {
            alphabet[t.charAt(i) - 'a']--;
        }
        for (int i : alphabet) {
            if (i != 0) {
                return false;
            }
        }
        return true;
    }
}
