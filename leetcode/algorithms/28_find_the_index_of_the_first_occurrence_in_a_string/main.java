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
  public int strStr(String haystack, String needle) {
    int haystackLen = haystack.length();
    int needleLen = needle.length();

    if (needleLen > haystackLen) {
      return -1;
    }

    char[] haystackCharArray = haystack.toCharArray();
    char[] needleCharArray = needle.toCharArray();

    for (int haystackIdx = 0; haystackIdx <= haystackLen - needleLen; haystackIdx++) {
      boolean isMatch = true;

      for (int needleIdx = 0; needleIdx < needleLen; needleIdx++) {
        if (haystackCharArray[haystackIdx + needleIdx] != needleCharArray[needleIdx]) {
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
   * Brute Force, Sliding Window
   *
   * Complexities:
   *   N - Length of `haystack`
   *   M - Length of `needle`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(1)
   */
  public int solution(String haystack, String needle) {
    int n = haystack.length();
    int m = needle.length();

    if (m > n) {
      return -1;
    }

    for (int i = 0; i <= n - m; i++) {
      int j = 0;

      while (j < m) {
        if (haystack.charAt(i + j) != needle.charAt(j)) {
          break;
        }
        j++;
      }

      if (j == m) {
        return i;
      }
    }

    return -1;
  }
}
