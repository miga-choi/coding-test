class HammingDistance {
    public int hammingDistance(int x, int y) {
        return Integer.toString(x ^ y, 2).replaceAll("0", "").length();
    }


    // Best Solution
    public int bestSolution(int x, int y) {
        return Integer.bitCount(x ^ y);
    }
}