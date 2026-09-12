class RansomNote {
  /**
   * Counting Array
   *
   * Complexities:
   *   N - The size of `ransomNote`
   *   M - The size of `magazine`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(1)
   */
  bool canConstruct(String ransomNote, String magazine) {
    List<int> alphabetArray = List<int>.filled(26, 0);

    for (int c in magazine.codeUnits) {
      alphabetArray[c - 97] = alphabetArray[c - 97] + 1;
    }

    for (int c in ransomNote.codeUnits) {
      if (alphabetArray[c - 97] > 0) {
        alphabetArray[c - 97] = alphabetArray[c - 97] - 1;
      } else {
        return false;
      }
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Counting Array
   *
   * Complexities:
   *   N - The Size of `ransomNote`
   *   M - The Size of `magazine`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(1)
   */
  bool solution1(String ransomNote, String magazine) {
    if (ransomNote.length > magazine.length) {
      return false;
    }

    final a = 'a'.codeUnitAt(0);
    final counts = List<int>.filled(26, 0);

    for (final c in magazine.codeUnits) {
      counts[c - a]++;
    }

    for (final c in ransomNote.codeUnits) {
      if (--counts[c - a] < 0) {
        return false;
      }
    }

    return true;
  }

  /**
   * Solution 2
   * 
   * Map
   *
   * Complexities:
   *   N - The Size of `ransomNote`
   *   M - The Size of `magazine`
   *   K - The Size of Characters in `magazine`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(K)
   */
  bool solutio2(String ransomNote, String magazine) {
    if (ransomNote.length > magazine.length) {
      return false;
    }

    final counts = <int, int>{};

    for (final c in magazine.codeUnits) {
      counts.update(c, (v) => v + 1, ifAbsent: () => 1);
    }

    for (final c in ransomNote.codeUnits) {
      final left = counts[c] ?? 0;

      if (left == 0) {
        return false;
      }

      counts[c] = left - 1;
    }

    return true;
  }
}
