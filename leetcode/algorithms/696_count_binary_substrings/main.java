class CountBinarySubstrings {
    public int countBinarySubstrings(String s) {
        int count = 1;
        int prevCount = 0;
        int result = 0;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i) == s.charAt(i - 1)) {
                count++;
            } else {
                result += Math.min(count, prevCount);
                prevCount = count;
                count = 1;
            }
        }

        return result + Math.min(count, prevCount);
    }


    // Solution
    // Solution 1: Group By Character
    public int solution1(String s) {
        int[] groups = new int[s.length()];
        int t = 0;

        groups[0] = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) != s.charAt(i)) {
                groups[++t] = 1;
            } else {
                groups[t]++;
            }
        }

        int ans = 0;
        for (int i = 1; i <= t; i++) {
            ans += Math.min(groups[i - 1], groups[i]);
        }

        return ans;
    }

    // Solution 2: Linear Scan
    public int solution2(String s) {
        int ans = 0, prev = 0, cur = 1;

        for (int i = 1; i < s.length(); i++) {
            if (s.charAt(i - 1) != s.charAt(i)) {
                ans += Math.min(prev, cur);
                prev = cur;
                cur = 1;
            } else {
                cur++;
            }
        }

        return ans + Math.min(prev, cur);
    }
}
