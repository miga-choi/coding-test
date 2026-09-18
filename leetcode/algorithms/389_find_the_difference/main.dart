class FindTheDifference {
  /**
   * replaceFirst
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N²)
   *   - Space Complexity: O(N)
   */
  String findTheDifference(String s, String t) {
    for (String c in s.split("")) {
      t = t.replaceFirst(c, "");
    }

    return t;
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
  String solution1(String s, String t) {
    final a = 'a'.codeUnitAt(0);
    final counts = List<int>.filled(26, 0);

    for (final c in t.codeUnits) {
      counts[c - a]++;
    }

    for (final c in s.codeUnits) {
      counts[c - a]--;
    }

    for (var i = 0; i < 26; i++) {
      if (counts[i] > 0) return String.fromCharCode(a + i);
    }

    return '';
  }

  /**
   * Solution 2
   *
   * XOR
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  String solution2(String s, String t) {
    var xor = 0;

    for (final c in s.codeUnits) {
      xor ^= c;
    }
    for (final c in t.codeUnits) {
      xor ^= c;
    }

    return String.fromCharCode(xor);
  }

  /**
   * Solution 3
   *
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  String solution3(String s, String t) {
    var sum = 0;

    for (final c in t.codeUnits) {
      sum += c;
    }
    for (final c in s.codeUnits) {
      sum -= c;
    }

    return String.fromCharCode(sum);
  }

  /**
   * Solution 4
   *
   * Sorting
   * 
   * Complexities:
   *   N - The Size of `s`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(1)
   */
  String solution4(String s, String t) {
    final a = s.split('')..sort();
    final b = t.split('')..sort();

    for (var i = 0; i < a.length; i++) {
      if (a[i] != b[i]) return b[i];
    }

    return b.last;
  }
}
