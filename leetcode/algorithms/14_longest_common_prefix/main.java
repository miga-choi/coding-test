import java.util.Arrays;

class LongestCommonPrefix {
    public String longestCommonPrefix(String[] strs) {
        String result = "";

        for (int i = 0; i < strs[0].length(); i++) {
            char c = strs[0].charAt(i);
            int count = 0;
            for (String str : strs) {
                if (i > str.length() - 1 || str.charAt(i) != c) {
                    return result;
                }
                count++;
                if (count == strs.length) {
                    result += c;
                }
            }
        }

        return result;
    }


    // Best Solution
    // Best Solution 1:
    public String bestSolution1(String[] strs) {
        StringBuilder ans = new StringBuilder();
        Arrays.sort(strs);
        String first = strs[0];
        String last = strs[strs.length - 1];
        for (int i = 0; i < Math.min(first.length(), last.length()); i++) {
            if (first.charAt(i) != last.charAt(i)) {
                return ans.toString();
            }
            ans.append(first.charAt(i));
        }
        return ans.toString();
    }

    // Best Solution 2:
    public String bestSolution2(String[] strs) {
        Arrays.sort(strs);
        String s1 = strs[0];
        String s2 = strs[strs.length - 1];
        int idx = 0;
        while (idx < s1.length() && idx < s2.length()) {
            if (s1.charAt(idx) == s2.charAt(idx)) {
                idx++;
            } else {
                break;
            }
        }
        return s1.substring(0, idx);
    }

    // Best Solution 3:
    public String bestSolution3(String[] strs) {
        String prefix = strs[0];
        for (int index = 1; index < strs.length; index++) {
            while (strs[index].indexOf(prefix) != 0) {
                prefix = prefix.substring(0, prefix.length() - 1);
            }
        }
        return prefix;
    }
}