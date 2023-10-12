class RepeatedSubstringPattern {
    public boolean repeatedSubstringPattern(String s) {
        return s.substring(1).concat(s.substring(0, s.length() - 1)).contains(s);
    }


    // Best Solution
    public boolean bestSolution(String s) {
        int l = s.length();
        for (int i = l / 2; i >= 1; i--) {
            if (l % i == 0) {
                int m = l / i;
                String subS = s.substring(0, i);
                StringBuilder sb = new StringBuilder();
                for (int j = 0; j < m; j++) {
                    sb.append(subS);
                }
                if (sb.toString().equals(s))
                    return true;
            }
        }
        return false;
    }
}