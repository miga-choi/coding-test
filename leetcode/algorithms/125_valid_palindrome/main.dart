class ValidPalindrome {
  /*
   * Two-Pointers
   * 
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool isPalindrome(String s) {
    int left = 0;
    int right = s.length - 1;

    s = s.toLowerCase();

    while (left < right) {
      final int leftCodeUnit = s[left].codeUnitAt(0);
      final int rightCodeUnit = s[right].codeUnitAt(0);
      if (!(leftCodeUnit >= 48 && leftCodeUnit <= 57) &&
          !(leftCodeUnit >= 97 && leftCodeUnit <= 122)) {
        left++;
        continue;
      }

      if (!(rightCodeUnit >= 48 && rightCodeUnit <= 57) &&
          !(rightCodeUnit >= 97 && rightCodeUnit <= 122)) {
        right--;
        continue;
      }

      if (s[left] != s[right]) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }


  // Solution
  /*
   * Two-Pointers
   * 
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  bool solution(String s) {
    if (s.isEmpty) {
      return true;
    }

    int left = 0;
    int right = s.length - 1;

    while (left < right) {
      int leftCode = s.codeUnitAt(left);
      while (left < right && !_isAlphanumeric(leftCode)) {
        left++;
        leftCode = s.codeUnitAt(left);
      }

      int rightCode = s.codeUnitAt(right);
      while (left < right && !_isAlphanumeric(rightCode)) {
        right--;
        rightCode = s.codeUnitAt(right);
      }

      if (left < right) {
        int leftLower = _toLowerCase(leftCode);
        int rightLower = _toLowerCase(rightCode);

        if (leftLower != rightLower) {
          return false;
        }

        left++;
        right--;
      }
    }

    return true;
  }

  bool _isAlphanumeric(int code) {
    return (code >= 48 && code <= 57) ||
        (code >= 65 && code <= 90) ||
        (code >= 97 && code <= 122);
  }

  int _toLowerCase(int code) {
    if (code >= 65 && code <= 90) {
      return code + 32;
    }
    return code;
  }
}
