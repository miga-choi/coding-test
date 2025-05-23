import java.util.HashMap;
import java.util.Map;

class WordPattern {
    public boolean wordPattern(String pattern, String s) {
        String[] sArray = s.split(" ");

        if (sArray.length != pattern.length()) {
            return false;
        }

        Map<Character, String> sMap = new HashMap<Character, String>();

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
    public boolean solution(String pattern, String str) {
        String[] words = str.split(" ");

        if (words.length != pattern.length()) {
            return false;
        }

        Map<String, Integer> index = new HashMap<String, Integer>();

        for (Integer i = 0; i < words.length; ++i) {
            if (index.put(String.valueOf(pattern.charAt(i)), i) != index.put(words[i], i)) {
                return false;
            }
        }

        return true;
    }
}
