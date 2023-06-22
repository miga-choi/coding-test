class NumberOf1Bits {

  // you need to treat n as an unsigned value
  public int hammingWeight(int n) {
    return Integer.toBinaryString(n).replaceAll("0", "").length();
  }

  // Best Solution
  public static int bestSolution(int n) {
    int ones = 0;
    while (n != 0) {
      ones = ones + (n & 1);
      n = n >>> 1;
    }
    return ones;
  }
}
