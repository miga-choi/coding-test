class ValidPalindrome {
  /*
   * Two-Pointer
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
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
  /*
   * Solution 1
   * 
   * Compare strings
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
   */
  public boolean solution1(String s) {
    StringBuilder filteredChars = new StringBuilder();

    for (char c : s.toCharArray()) {
      if (Character.isLetterOrDigit(c)) {
        filteredChars.append(Character.toLowerCase(c));
      }
    }

    String original = filteredChars.toString();
    String reversed = filteredChars.reverse().toString();

    return original.equals(reversed);
  }

  /*
   * Solution 2
   * 
   * Two-Pointer
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public boolean solution2(String s) {
    int left = 0;
    int right = s.length() - 1;

    while (left < right) {
      char leftChar = s.charAt(left);
      char rightChar = s.charAt(right);

      if (!Character.isLetterOrDigit(leftChar)) {
        left++;
        continue;
      }

      if (!Character.isLetterOrDigit(rightChar)) {
        right--;
        continue;
      }

      if (Character.toLowerCase(leftChar) != Character.toLowerCase(rightChar)) {
        return false;
      }

      left++;
      right--;
    }

    return true;
  }
}
