import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

class LongestPalindrome {
    public int longestPalindrome(String s) {
        int result = 0;
        Map<Character, Integer> sMap = new HashMap<Character, Integer>();

        for (char c : s.toCharArray()) {
            if (sMap.get(c) == null) {
                sMap.put(c, 1);
            } else {
                result += 2;
                sMap.remove(c);
            }
        }

        if (sMap.size() > 0) {
            result++;
        }

        return result;
    }


    // Best Solution
    public int bestSolution1(String s) {
        if (s == null || s.length() == 0)
            return 0;

        HashSet<Character> hs = new HashSet<Character>();
        int count = 0;

        for (int i = 0; i < s.length(); i++) {
            if (hs.contains(s.charAt(i))) {
                hs.remove(s.charAt(i));
                count++;
            } else {
                hs.add(s.charAt(i));
            }
        }

        if (!hs.isEmpty())
            return count * 2 + 1;

        return count * 2;
    }

    public int bestSolution2(String s) {
        int oddCount = 0;
        Map<Character, Integer> map = new HashMap<>();
        for (char ch : s.toCharArray()) {
            map.put(ch, map.getOrDefault(ch, 0) + 1);
            if (map.get(ch) % 2 == 1)
                oddCount++;
            else
                oddCount--;
        }
        if (oddCount > 1)
            return s.length() - oddCount + 1;
        return s.length();
    }
}