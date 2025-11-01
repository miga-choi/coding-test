import 'dart:math';

class LongestPalindromicSubstring {
  /**
   * Expand Around Center
   * - Time Complexity: O(N²)
   * - Space Complexity: O(1)
   */
  int _getPalindromeLength(final String s, int left, int right) {
    while (left >= 0 && right < s.length && s[left] == s[right]) {
      left--;
      right++;
    }
    return right - left - 1;
  }

  String longestPalindrome(String s) {
    if (s.length == 1) {
      return s;
    }

    int startIndex = 0;
    int maxLength = 0;

    for (int i = 0; i < s.length; i++) {
      final int oddLength = _getPalindromeLength(s, i, i);
      final int evenLength = _getPalindromeLength(s, i, i + 1);

      final int currMaxLength = max(oddLength, evenLength);

      if (currMaxLength > maxLength) {
        maxLength = currMaxLength;
        startIndex = i - (maxLength - 1) ~/ 2;
      }
    }

    return s.substring(startIndex, startIndex + maxLength);
  }


  // Solution
  /**
   * Solution 1
   * 
   * Expand Around Center
   * - Time Complexity: O(N²)
   * - Space Complexity: O(1)
   */
  String _expand(String s, int left, int right) {
    while (left >= 0 && right < s.length && s[left] == s[right]) {
      left--;
      right++;
    }

    // 루프 종료 후, 실제 Palindrome의 범위는 (left, right) 안쪽.
    // substring의 end 인덱스는 exclusive이므로 right를 그대로 사용.
    return s.substring(left + 1, right);
  }

  String solution1(String s) {
    if (s.length < 2) {
      return s;
    }

    String longest = "";

    for (int i = 0; i < s.length; i++) {
      // 홀수 길이 Palindrome (중심: i)
      String oddPalindrome = _expand(s, i, i);
      if (oddPalindrome.length > longest.length) {
        longest = oddPalindrome;
      }

      // 짝수 길이 Palindrome (중심: i, i+1)
      String evenPalindrome = _expand(s, i, i + 1);
      if (evenPalindrome.length > longest.length) {
        longest = evenPalindrome;
      }
    }

    return longest;
  }

  /**
   * Solution 2
   * 
   * Dynamic Programming
   * - Time Complexity: O(N²)
   * - Space Complexity: O(N²)
   */
  String solution2(String s) {
    int n = s.length;

    if (n < 2) {
      return s;
    }

    // dp 테이블 생성 및 false로 초기화
    List<List<bool>> dp = List.generate(n, (_) => List.filled(n, false));
    int start = 0, maxLength = 1;

    // 길이가 1인 경우는 모두 회문
    for (int i = 0; i < n; i++) {
      dp[i][i] = true;
    }

    // 길이가 2인 경우를 확인
    for (int i = 0; i < n - 1; i++) {
      if (s[i] == s[i + 1]) {
        dp[i][i + 1] = true;
        start = i;
        maxLength = 2;
      }
    }

    // 길이가 3 이상인 경우를 확인
    for (int len = 3; len <= n; len++) {
      for (int i = 0; i <= n - len; i++) {
        int j = i + len - 1; // 끝 인덱스

        // 점화식 적용
        if (s[i] == s[j] && dp[i + 1][j - 1]) {
          dp[i][j] = true;
          start = i;
          maxLength = len;
        }
      }
    }

    return s.substring(start, start + maxLength);
  }
}
