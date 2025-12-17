class LongestCommonPrefix {
  String longestCommonPrefix(List<String> strs) {
    String result = "";

    for (int i = 0; i < strs[0].length; i++) {
      String c = strs[0][i];
      int count = 0;
      for (String str in strs) {
        if (i > str.length - 1 || str[i] != c) {
          return result;
        }
        count++;
        if (count == strs.length) {
          result += c;
        }
      }
    }

    return result;
  }

  // Solution
  /**
   * Solution 1
   *
   * Horizontal Scanning
   *
   * Complexities:
   *   S - Quantity of characters in `strs`
   *   - Time Complexity: O(S)
   *   - Space Complexity: O(1)
   */
  String solution1(List<String> strs) {
    String prefix = strs[0];

    for (int i = 1; i < strs.length; i++) {
      while (!strs[i].startsWith(prefix)) {
        prefix = prefix.substring(0, prefix.length - 1);

        if (prefix.isEmpty) {
          return "";
        }
      }
    }

    return prefix;
  }

  /**
   * Solution 2
   *
   * Sorting
   *
   * Complexities:
   *   N - Length of `strs`
   *   L - Length of Longest `str` in `strs`
   *   - Time Complexity: O(N * L * logᴺ)
   *   - Space Complexity: O(logᴺ)
   */
  String solution2(List<String> strs) {
    strs.sort();

    String s1 = strs.first;
    String s2 = strs.last;

    int idx = 0;

    while (idx < s1.length && idx < s2.length) {
      if (s1[idx] == s2[idx]) {
        idx++;
      } else {
        break;
      }
    }

    return s1.substring(0, idx);
  }
}
