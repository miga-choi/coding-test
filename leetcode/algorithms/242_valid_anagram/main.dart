class ValidAnagram {
  /**
   * Frequency Counting
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool isAnagram(String s, String t) {
    int len = s.length;

    if (len != t.length) {
      return false;
    }

    List<int> alphabetNumArray = List<int>.filled(26, 0);

    for (int i = 0; i < len; i++) {
      alphabetNumArray[s.codeUnitAt(i) - 97]++;
      alphabetNumArray[t.codeUnitAt(i) - 97]--;
    }

    for (int i = 0; i < 26; i++) {
      if (alphabetNumArray[i] != 0) {
        return false;
      }
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Frequency Counting
   *
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool solution1(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    final List<int> charCounts = List.filled(26, 0);
    final int asciiA = 'a'.codeUnitAt(0);

    for (int i = 0; i < s.length; i++) {
      charCounts[s.codeUnitAt(i) - asciiA]++;
      charCounts[t.codeUnitAt(i) - asciiA]--;
    }

    for (int count in charCounts) {
      if (count != 0) return false;
    }

    return true;
  }

  /**
   * Solution 2
   * 
   * Hash Map
   * 
   * Complexities:
   *   N - The size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  bool solution2(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    final Map<String, int> charCounts = {};

    for (int i = 0; i < s.length; i++) {
      String charS = s[i];
      String charT = t[i];

      charCounts[charS] = (charCounts[charS] ?? 0) + 1;
      charCounts[charT] = (charCounts[charT] ?? 0) - 1;
    }

    for (int count in charCounts.values) {
      if (count != 0) return false;
    }

    return true;
  }
}
