class ValidAnagram {
  /**
   * Frequency Counter
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
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
   * Sort
   * - Time Complexity: O(N * logᴺ)
   * - Space Complexity: O(N)
   */
  bool solution1(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    List<String> sChars = s.split('');
    List<String> tChars = t.split('');

    sChars.sort();
    tChars.sort();

    return sChars.join('') == tChars.join('');
  }

  /**
   * Solution 2
   * 
   * Hash Map
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  bool solution2(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    Map<String, int> charCount = {};

    for (int i = 0; i < s.length; i++) {
      charCount[s[i]] = (charCount[s[i]] ?? 0) + 1;
    }

    for (int i = 0; i < t.length; i++) {
      String char = t[i];

      if (!charCount.containsKey(char) || charCount[char] == 0) {
        return false;
      }

      charCount[char] = charCount[char]! - 1;
    }

    return true;
  }
}
