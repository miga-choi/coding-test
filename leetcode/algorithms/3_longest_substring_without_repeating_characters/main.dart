import 'dart:math';

class LongestSubstringWithoutRepeatingCharacters {
  /**
   * Sliding Window
   *
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int lengthOfLongestSubstring(String s) {
    List<int> charMap = List<int>.filled(128, -1);
    int left = 0;
    int maxLength = 0;

    for (int right = 0; right < s.length; right++) {
      int currentCharCode = s.codeUnitAt(right);

      if (charMap[currentCharCode] >= left) {
        left = charMap[currentCharCode] + 1;
      }

      charMap[currentCharCode] = right;

      maxLength = max(maxLength, right - left + 1);
    }

    return maxLength;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Sliding Window (Using Map)
   *
   * Complexities:
   *   N - Length of `s`
   *   M - Length of Available Characters in `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(Min(M, N))
   */
  int solution(String s) {
    int maxLength = 0;
    int left = 0;

    Map<String, int> lastSeen = {};

    for (int right = 0; right < s.length; right++) {
      String currentChar = s[right];

      if (lastSeen.containsKey(currentChar) && lastSeen[currentChar]! >= left) {
        left = lastSeen[currentChar]! + 1;
      }

      maxLength = max(maxLength, right - left + 1);

      lastSeen[currentChar] = right;
    }

    return maxLength;
  }

  /**
   * Solution 2
   * 
   * Sliding Window (Using List)
   *
   * Complexities:
   *   N - Length of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(String s) {
    int maxLength = 0;
    int left = 0;

    List<int> lastSeen = List.filled(128, -1);
    List<int> codes = s.codeUnits;

    for (int right = 0; right < codes.length; right++) {
      int charCode = codes[right];

      if (lastSeen[charCode] >= left) {
        left = lastSeen[charCode] + 1;
      }

      maxLength = max(maxLength, right - left + 1);
      lastSeen[charCode] = right;
    }

    return maxLength;
  }
}
