class NumberOf1Bits {
  // you need to treat n as an unsigned value
  public int hammingWeight(int n) {
    return Integer.toBinaryString(n).replaceAll("0", "").length();
  }


  // Solution
  public static int solution(int n) {
    int ones = 0;
    while (n != 0) {
      ones = ones + (n & 1);
      n = n >>> 1;
    }
    return ones;
  }
}
