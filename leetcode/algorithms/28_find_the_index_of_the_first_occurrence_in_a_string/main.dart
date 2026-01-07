class FindTheIndexOfTheFirstOccurrenceInAString {
  /**
   * Brute Force, Sliding Window
   *
   * Complexities:
   *   N - Length of `haystack`
   *   M - Length of `needle`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(1)
   */
  int strStr(String haystack, String needle) {
    int haystackLen = haystack.length;
    int needleLen = needle.length;

    if (needleLen > haystackLen) {
      return -1;
    }

    for (
      int haystackIdx = 0;
      haystackIdx <= haystackLen - needleLen;
      haystackIdx++
    ) {
      bool isMatch = true;

      for (int needleIdx = 0; needleIdx < needleLen; needleIdx++) {
        if (haystack[haystackIdx + needleIdx] != needle[needleIdx]) {
          isMatch = false;
          break;
        }
      }

      if (isMatch) {
        return haystackIdx;
      }
    }

    return -1;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Brute Force, Sliding Window
   *
   * Complexities:
   *   N - Length of `haystack`
   *   M - Length of `needle`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(1)
   */
  int solution1(String haystack, String needle) {
    int n = haystack.length;
    int m = needle.length;

    for (int i = 0; i <= n - m; i++) {
      int j = 0;

      while (j < m && haystack[i + j] == needle[j]) {
        j++;
      }

      if (j == m) {
        return i;
      }
    }

    return -1;
  }

  /**
   * Solution 2
   * 
   * built-in: indexOf()
   *
   * Complexities:
   *   N - Length of `haystack`
   *   M - Length of `needle`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(1)
   */
  int solution2(String haystack, String needle) {
    return haystack.indexOf(needle);
  }
}
