import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashMap;
import java.util.List;
import java.util.Map;

class GroupAnagrams {
    /**
     * Complexities:
     * N - size of strs
     * K - max size of strings in strs
     * - Time Complexity: O(N * K * logᴷ)
     * - Space Complexity: O(N * K)
     */
    public List<List<String>> groupAnagrams(String[] strs) {
        Map<String, List<String>> strMap = new HashMap<>();

        for (String str : strs) {
            char[] strArray = str.toCharArray();
            Arrays.sort(strArray);
            String sortedStr = new String(strArray);

            if (!strMap.containsKey(sortedStr)) {
                strMap.put(sortedStr, new ArrayList<>());
            }

            strMap.get(sortedStr).add(str);
        }

        return new ArrayList<>(strMap.values());
    }


    // Solution
    /**
     * Solution 1
     * 
     * Sorted String as Key
     * 
     * Complexities:
     * N - size of strs
     * K - max size of strings in strs
     * - Time Complexity: O(N * K * logᴷ)
     * - Space Complexity: O(N * K)
     */
    public List<List<String>> solution1(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            char[] charArray = s.toCharArray();

            Arrays.sort(charArray);

            String key = new String(charArray);

            map.computeIfAbsent(key, k -> new ArrayList<>());
            map.get(key).add(s);
        }

        return new ArrayList<>(map.values());
    }

    /**
     * Solution 2
     * 
     * Character Count as Key
     * 
     * Complexities:
     * N - size of strs
     * K - max size of strings in strs
     * - Time Complexity: O(N * K)
     * - Space Complexity: O(N * K)
     */
    public List<List<String>> solution2(String[] strs) {
        Map<String, List<String>> map = new HashMap<>();

        for (String s : strs) {
            char[] counts = new char[26];

            for (char c : s.toCharArray()) {
                counts[c - 'a']++;
            }

            String key = new String(counts);

            map.computeIfAbsent(key, k -> new ArrayList<>());
            map.get(key).add(s);
        }

        return new ArrayList<>(map.values());
    }
}
