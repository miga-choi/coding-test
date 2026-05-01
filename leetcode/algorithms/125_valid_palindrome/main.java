class ValidPalindrome {
  /**
   * Regex
   *
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public boolean isPalindrome(String s) {
    s = s.toLowerCase().replaceAll("[^a-z0-9]", "");

    for (int left = 0, right = s.length() - 1; left < right; left++, right--) {
      if (s.charAt(left) != s.charAt(right)) {
        return false;
      }
    }

    return true;
  }


  // Solution
  /**
   * Solution 1
   * 
   * Regex
   *
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public boolean solution1(String s) {
    String cleaned = s.replaceAll("[^A-Za-z0-9]", "").toLowerCase();

    String reversed = new StringBuilder(cleaned).reverse().toString();

    return cleaned.equals(reversed);
  }

  /*
   * Solution 2
   * 
   * Two-Pointers
   * 
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public boolean solution2(String s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
      char charLeft = s.charAt(left);
      char charRight = s.charAt(right);

      if (!Character.isLetterOrDigit(charLeft)) {
        left++;
      } else if (!Character.isLetterOrDigit(charRight)) {
        right--;
      } else {
        if (Character.toLowerCase(charLeft) != Character.toLowerCase(charRight)) {
          return false;
        }

        left++;
        right--;
      }
    }

    return true;
  }
}
