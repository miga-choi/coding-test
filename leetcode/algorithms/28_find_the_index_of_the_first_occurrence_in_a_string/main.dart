class FindTheIndexOfTheFirstOccurrenceInAString {
  /**
   * Brute-Force
   * - Time Complexity: O(N * M)
   * - Space Complexity: O(1)
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
   * String indexOf()
   * - Time Complexity: O(N * M)
   * - Space Complexity: O(1)
   */
  int solution1(String haystack, String needle) {
    return haystack.indexOf(needle);
  }

  /**
   * Solution 2
   * 
   * Knuth-Morris-Pratt (KMP)
   * - Time Complexity: O(N + M)
   * - Space Complexity: O(M)
   */
  List<int> _computeLPSArray(String needle) {
    int needleLen = needle.length;
    List<int> lps = List.filled(needleLen, 0);
    int length = 0;
    int idx = 1;

    while (idx < needleLen) {
      if (needle[idx] == needle[length]) {
        length++;
        lps[idx] = length;
        idx++;
      } else {
        if (length != 0) {
          length = lps[length - 1];
        } else {
          lps[idx] = 0;
          idx++;
        }
      }
    }

    return lps;
  }

  int solution2(String haystack, String needle) {
    int haystackLen = haystack.length;
    int needleLen = needle.length;

    if (needleLen > haystackLen) {
      return -1;
    }

    List<int> lps = _computeLPSArray(needle);

    int haystackIdx = 0;
    int needleIdx = 0;

    while (haystackIdx < haystackLen) {
      if (haystack[haystackIdx] == needle[needleIdx]) {
        haystackIdx++;
        needleIdx++;
      }

      if (needleIdx == needleLen) {
        return haystackIdx - needleIdx;
      } else if (haystackIdx < haystackLen &&
          haystack[haystackIdx] != needle[needleIdx]) {
        if (needleIdx != 0) {
          needleIdx = lps[needleIdx - 1];
        } else {
          haystackIdx++;
        }
      }
    }

    return -1;
  }
}
