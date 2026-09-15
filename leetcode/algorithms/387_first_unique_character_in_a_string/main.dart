class FirstUniqueCharacterInAString {
  /**
   * Counting Array + Two-Pass
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int firstUniqChar(String s) {
    final List<int> alphabetNumArray = List<int>.filled(26, 0);
    final int sLength = s.length;

    for (int i = 0; i < sLength; i++) {
      alphabetNumArray[s.codeUnitAt(i) - 97]++;
    }

    for (int i = 0; i < sLength; i++) {
      if (alphabetNumArray[s.codeUnitAt(i) - 97] == 1) {
        return i;
      }
    }

    return -1;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Counting Array + Two-Pass
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(String s) {
    final a = 'a'.codeUnitAt(0);
    final counts = List<int>.filled(26, 0);
    final codes = s.codeUnits;

    for (final c in codes) {
      counts[c - a]++;
    }

    for (var i = 0; i < codes.length; i++) {
      if (counts[codes[i] - a] == 1) {
        return i;
      }
    }

    return -1;
  }

  /**
   * Solution 2
   *
   * Counting Array + Indexing + 1.5-Pass
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(String s) {
    final a = 'a'.codeUnitAt(0);
    final first = List<int>.filled(26, -1);
    final codes = s.codeUnits;

    for (var i = 0; i < codes.length; i++) {
      final k = codes[i] - a;

      if (first[k] == -1) {
        first[k] = i;
      } else {
        first[k] = -2;
      }
    }

    var ans = -1;

    for (final idx in first) {
      if (idx >= 0 && (ans == -1 || idx < ans)) {
        ans = idx;
      }
    }

    return ans;
  }

  /**
   * Solution 3
   *
   * Map
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution3(String s) {
    final counts = <int, int>{};

    for (final c in s.codeUnits) {
      counts.update(c, (v) => v + 1, ifAbsent: () => 1);
    }

    for (var i = 0; i < s.length; i++) {
      if (counts[s.codeUnitAt(i)] == 1) {
        return i;
      }
    }

    return -1;
  }
}
