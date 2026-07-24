class UglyNumber {
  /**
   * Iterative Division
   *
   * Complexities:
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(N)
   */
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


  // Solution
  /**
   * Iterative Division
   *
   * Complexities:
   *   - Time Complexity: O(logᴺ)
   *   - Space Complexity: O(N)
   */
  bool solution(int n) {
    if (n <= 0) {
      return false;
    }

    final List<int> factors = [2, 3, 5];

    for (int factor in factors) {
      while (n % factor == 0) {
        n = n ~/ factor;
      }
    }

    return n == 1;
  }
}
