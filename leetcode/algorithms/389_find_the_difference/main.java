class FindTheDifference {
    public char findTheDifference(String s, String t) {
        for (int i = 0; i < s.length(); i++) {
            t = t.replaceFirst(String.valueOf(s.charAt(i)), "");
        }
        return t.charAt(0);
    }


    // Best Solution
    public char bestSolution(String s, String t) {
        char c = 0;
        for (char cs : s.toCharArray())
            c ^= cs;
        for (char ct : t.toCharArray())
            c ^= ct;
        return c;
    }
}