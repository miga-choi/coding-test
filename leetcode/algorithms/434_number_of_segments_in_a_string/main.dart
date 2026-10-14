class NumberOfSegmentsInAString {
  /**
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int countSegments(String s) {
    List<String> sArray = s.split("");
    sArray.removeWhere((v) => v.trim().isNotEmpty);

    return sArray.length;
  }


  // Solution
  /**
   * Solution 1
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(String s) {
    const space = 32;
    final codes = s.codeUnits;
    var count = 0;

    for (var i = 0; i < codes.length; i++) {
      if (codes[i] != space && (i == 0 || codes[i - 1] == space)) {
        count++;
      }
    }

    return count;
  }

  /**
   * Solution 2
   *
   * Status flag
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(String s) {
    var count = 0;
    var inSegment = false;

    for (final c in s.codeUnits) {
      if (c == 32) {
        inSegment = false;
      } else if (!inSegment) {
        inSegment = true;
        count++;
      }
    }

    return count;
  }

  /**
   * Solution 3
   *
   * Built-in Function
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  int solution3(String s) => s.split(' ').where((w) => w.isNotEmpty).length;
}
