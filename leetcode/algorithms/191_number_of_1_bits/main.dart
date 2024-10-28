class NumberOf1Bits {
  int hammingWeight(int n) {
    int count = 0;

    for (int i = 0; i < 32; i++) {
      if ((n & 1) != 0) {
        count++;
      }
      n = n >> 1;
    }

    return count;
  }

  // Best Solution
  int bestSolution(int n) {
    int res = 0;
    while (n > 0) {
      n &= n - 1;
      res++;
    }
    return res;
  }
}
