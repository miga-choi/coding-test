class RepeatedSubstringPattern {
  /**
   * String Concatenation
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N) ~ O(N²)
   *   - Space Complexity: O(N)
   */
  bool repeatedSubstringPattern(String s) {
    return (s + s).substring(1, s.length * 2 - 1).contains(s);
  }


  // Solution
  /**
   * Solution 1
   *
   * Divisor Enumeration
   *
   * Complexities:
   *   N - The Size of `s`
   *   d(N) - The Number of Divisors of N
   *   - Time Complexity: O(N * d(N))
   *   - Space Complexity: O(1)
   */
  bool solution1(String s) {
    final c = s.codeUnits;
    final n = c.length;

    for (var len = 1; len <= n ~/ 2; len++) {
      if (n % len != 0) {
        continue;
      }

      var ok = true;
      for (var i = len; i < n; i++) {
        if (c[i] != c[i - len]) {
          ok = false;
          break;
        }
      }

      if (ok) {
        return true;
      }
    }

    return false;
  }

  /**
   * Solution 2
   *
   * String Concatenation
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N) ~ O(N²)
   *   - Space Complexity: O(N)
   */
  bool solution2(String s) {
    final doubled = s + s;
    return doubled.substring(1, doubled.length - 1).contains(s);
  }

  /**
   * Solution 3
   *
   * KMP Failure Function
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution3(String s) {
    final c = s.codeUnits;
    final n = c.length;
    final lps = List<int>.filled(n, 0);

    var len = 0;
    for (var i = 1; i < n; i++) {
      while (len > 0 && c[i] != c[len]) {
        len = lps[len - 1];
      }

      if (c[i] == c[len]) {
        len++;
      }

      lps[i] = len;
    }

    final l = lps[n - 1];
    return l > 0 && n % (n - l) == 0;
  }
}
