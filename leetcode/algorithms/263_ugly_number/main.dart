class UglyNumber {
  bool isUgly(int n) {
    while (n > 1) {
      if (n % 5 == 0) {
        n = (n / 5).floor();
        continue;
      }
      if (n % 3 == 0) {
        n = (n / 3).floor();
        continue;
      }
      if (n % 2 == 0) {
        n = (n / 2).floor();
        continue;
      }
      break;
    }
    return n == 1;
  }

  // Best Solution
  bool bestSolution(int n) {
    for (int i = 2; i < 6 && n != 0; i++) {
      while (n % i == 0) {
        n = (n / i).floor();
      }
    }
    return n == 1;
  }
}
