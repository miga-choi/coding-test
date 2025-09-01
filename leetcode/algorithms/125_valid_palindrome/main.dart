class ValidPalindrome {
  /*
   * Two-Pointer
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
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
   * Solution 1
   * 
   * Compare strings
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  bool solution1(String s) {
    String sanitized = s.replaceAll(RegExp(r'[^A-Za-z0-9]'), '').toLowerCase();

    String reversed = sanitized.split('').reversed.join('');

    return sanitized == reversed;
  }

  /*
   * Solution 2
   * 
   * Two-Pointer
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  bool _isAlphanumeric(String char) {
    final int code = char.codeUnitAt(0);
    return (code >= 97 && code <= 122) ||
        (code >= 65 && code <= 90) ||
        (code >= 48 && code <= 57);
  }

  bool solution2(String s) {
    int left = 0;
    int right = s.length - 1;

    while (left < right) {
      while (left < right && !_isAlphanumeric(s[left])) {
        left++;
      }

      while (left < right && !_isAlphanumeric(s[right])) {
        right--;
      }

      if (s[left].toLowerCase() != s[right].toLowerCase()) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
}
