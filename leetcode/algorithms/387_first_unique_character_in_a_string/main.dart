class FirstUniqueCharacterInAString {
  /**
   * Frequency Counter
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
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
   * Frequency Counter
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  int solution1(String s) {
    List<int> counts = List.filled(26, 0);
    final int aCode = 'a'.codeUnitAt(0);

    for (int i = 0; i < s.length; i++) {
      int index = s.codeUnitAt(i) - aCode;
      counts[index]++;
    }

    for (int i = 0; i < s.length; i++) {
      int index = s.codeUnitAt(i) - aCode;
      if (counts[index] == 1) {
        return i;
      }
    }

    return -1;
  }

  /**
   * Solution 2
   * 
   * Hash table
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  int solution2(String s) {
    Map<String, int> counts = {};

    for (int i = 0; i < s.length; i++) {
      String char = s[i];
      counts[char] = (counts[char] ?? 0) + 1;
    }

    for (int i = 0; i < s.length; i++) {
      String char = s[i];
      if (counts[char] == 1) {
        return i;
      }
    }

    return -1;
  }

  /**
   * Solution 3
   * 
   * Brute-Force
   * - Time Complexity: O(N²)
   * - Space Complexity: O(1)
   */
  int solution3(String s) {
    for (int i = 0; i < s.length; i++) {
      bool isUnique = true;

      for (int j = 0; j < s.length; j++) {
        if (i != j && s[i] == s[j]) {
          isUnique = false;
          break;
        }
      }

      if (isUnique) {
        return i;
      }
    }

    return -1;
  }
}
