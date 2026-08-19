class CountingBits {
  /**
   * Time Complexity should <= O(N)
   *
   * Complexities:
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N * logᴺ)
   */
  List<int> countBits(int n) {
    List<int> result = List<int>.filled(n + 1, 0);

    for (int i = 0; i <= n; i++) {
      int sum = 0;
      int num = i;

      while (num > 0) {
        if (num % 2 == 1) {
          sum++;
        }
        num = (num / 2).floor();
      }

      result[i] = sum;
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution1(int n) {
    final dp = List<int>.filled(n + 1, 0);

    for (var i = 1; i <= n; i++) {
      dp[i] = dp[i >> 1] + (i & 1);
    }

    return dp;
  }

  /**
   * Solution 2
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution2(int n) {
    final dp = List<int>.filled(n + 1, 0);

    for (var i = 1; i <= n; i++) {
      dp[i] = dp[i & (i - 1)] + 1;
    }

    return dp;
  }

  /**
   * Solution 3
   * 
   * Time Complexity should <= O(N)
   *
   * Complexities:
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N * logᴺ)
   */
  List<int> solution3(int n) {
    final res = List<int>.filled(n + 1, 0);

    for (var i = 0; i <= n; i++) {
      var x = i, count = 0;

      while (x != 0) {
        x &= x - 1;
        count++;
      }

      res[i] = count;
    }

    return res;
  }
}
