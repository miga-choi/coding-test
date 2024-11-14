class PowerOfTwo {
  bool isPowerOfTwo(int n) {
    if (n <= 0) {
      return false;
    }

    while ((n / 2).floor() > 0) {
      if (n > 1 && (n % 2) != 0) {
        return false;
      }
      n = (n / 2).floor();
    }

    return true;
  }

  // Best Solution 1
  bool bestSolution1(int n) {
    if (n <= 0) {
      return false;
    }
    while (n > 1) {
      if (n % 2 != 0) {
        return false;
      }
      n = n ~/ 2;
    }
    return true;
  }

  // Best Solution 2
  bool bestSolution2(int n) {
    return n > 0 && (n & (n - 1)) == 0;
  }
}
