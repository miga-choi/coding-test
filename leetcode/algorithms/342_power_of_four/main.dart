class PowerOfFour {
  bool isPowerOfFour(int n) {
    while (n > 1) {
      if (n % 4 > 0) {
        return false;
      }
      n = (n / 4).floor();
    }
    return n == 1;
  }

  // Best Solution
  bool bestSolution(int n) {
    if (n <= 0) {
      return false;
    }
    while (1 < n) {
      if (n % 4 != 0) {
        return false;
      }
      n ~/= 4;
    }
    return true;
  }
}
