class LongestPalindrome {
  /**
   * Bitwise XOR
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int longestPalindrome(String s) {
    int freq = 0;

    for (String c in s.split('')) {
      freq ^= (1 << (c.codeUnitAt(0) - 'A'.codeUnitAt(0)));
    }

    int hasOdd = 0;

    for (int i = 0; i <= 'z'.codeUnitAt(0) - 'A'.codeUnitAt(0); i++) {
      if (((freq >> i) & 1) == 1) {
        hasOdd++;
      }
    }

    return hasOdd > 1 ? s.length - hasOdd + 1 : s.length;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Counting Array
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(String s) {
    final counts = List<int>.filled(128, 0);

    for (final c in s.codeUnits) {
      counts[c]++;
    }

    var length = 0;
    var hasOdd = false;

    for (final cnt in counts) {
      length += cnt & ~1;

      if (cnt & 1 == 1) {
        hasOdd = true;
      }
    }

    return hasOdd ? length + 1 : length;
  }

  /**
   * Solution 2
   * 
   * Counting Array
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(String s) {
    final counts = List<int>.filled(128, 0);
    var pairs = 0;

    for (final c in s.codeUnits) {
      if (++counts[c] % 2 == 0) {
        pairs++;
      }
    }

    final length = pairs * 2;

    return length < s.length ? length + 1 : length;
  }

  /**
   * Solution 3
   * 
   * Set Toggle
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution3(String s) {
    final odd = <int>{};

    for (final c in s.codeUnits) {
      if (!odd.remove(c)) {
        odd.add(c);
      }
    }

    return odd.isEmpty ? s.length : s.length - odd.length + 1;
  }
}
