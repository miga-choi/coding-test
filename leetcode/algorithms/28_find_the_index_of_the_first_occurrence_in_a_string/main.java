class FindTheIndexOfTheFirstOccurrenceInAString {
  /**
   * Brute-Force
   * - Time Complexity: O(N * M)
   * - Space Complexity: O(1)
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
   * java.lang.String indexOf()
   * - Time Complexity: O(N * M)
   * - Space Complexity: O(1)
   */
  public int solution(String haystack, String needle) {
    return haystack.indexOf(needle);
  }
}
