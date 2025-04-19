class ValidPalindromeII {
  bool validPalindrome(String s) {
    for (int left = 0, right = s.length - 1; left < right; left++, right--) {
      if (s[left] != s[right]) {
        int left1 = left + 1, right1 = right;
        int left2 = left, right2 = right - 1;
        while (left1 < right1 && s[left1] == s[right1]) {
          left1++;
          right1--;
        }
        while (left2 < right2 && s[left2] == s[right2]) {
          left2++;
          right2--;
        }
        return left1 >= right1 || left2 >= right2;
      }
    }
    return true;
  }


  // Solution
  bool solution(String s) {
    bool isPalindrome(String str, int left, int right) {
      while (left < right) {
        if (str[left] != str[right]) return false;
        left++;
        right--;
      }
      return true;
    }

    int left = 0, right = s.length - 1;
    while (left < right) {
      if (s[left] != s[right]) {
        return isPalindrome(s, left + 1, right) ||
            isPalindrome(s, left, right - 1);
      }
      left++;
      right--;
    }
    return true;
  }
}
