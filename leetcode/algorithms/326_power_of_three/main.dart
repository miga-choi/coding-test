class PowerOfThree {
  bool isPowerOfThree(int n) {
    if (n > 1) {
      while (n % 3 == 0) {
        n = (n / 3).floor();
      }
    }
    return n == 1;
  }


  // Solution
  // Solution 1
  bool solution1(int n) {
    if (n <= 0) {
      return false;
    }

    while (n % 3 == 0) {
      n ~/= 3;
    }

    return n == 1;
  }

  // Solution 2
  bool solution2(int n) {
    for (var i = 1; i <= n; i *= 3) {
      if (i == n) {
        return true;
      }
    }
    return false;
  }
}
