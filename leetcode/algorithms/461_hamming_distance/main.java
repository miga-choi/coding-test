class HammingDistance {
    public int hammingDistance(int x, int y) {
        return Integer.toString(x ^ y, 2).replaceAll("0", "").length();
    }


    // Solution
    public int solution(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}
