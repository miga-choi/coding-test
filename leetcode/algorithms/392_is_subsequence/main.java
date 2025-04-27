class IsSubsequence {
    public boolean isSubsequence(String s, String t) {
        while (s.length() > 0) {
            int index = t.indexOf(s.charAt(0));
            if (index == -1) {
                return false;
            }
            t = t.substring(index + 1);
            s = s.substring(1, s.length());
        }
        return true;
    }


    // Solution
    public boolean solution(String s, String t) {
        int i = 0, j = 0;
        int n = t.length();
        int m = s.length();
        char ss[] = s.toCharArray();
        char tt[] = t.toCharArray();

        if (m < 1) {
            return true;
        }

        while (i < n) {
            if (tt[i] == ss[j]) {
                j++;
            }
            i++;

            if (j == m) {
                return true;
            }
        }

        return false;
    }
}
