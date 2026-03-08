class WordBreak {
  /**
   * Dynamic Programming
   *
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N³)
   *   - Space Complexity: O(N)
   */
  bool wordBreak(String s, List<String> wordDict) {
    final int sLen = s.length;

    final Set<String> dict = Set.from(wordDict);

    final List<bool> dp = List.filled(sLen + 1, false);
    dp[0] = true;

    for (int i = 1; i <= sLen; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && dict.contains(s.substring(j, i))) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[sLen];
  }


  // Solution
  /**
   * Dynamic Programming
   *
   * Complexities:
   *   N - Size of `s`
   *   - Time Complexity: O(N³)
   *   - Space Complexity: O(N)
   */
  bool solution(String s, List<String> wordDict) {
    final Set<String> wordSet = wordDict.toSet();

    final int n = s.length;
    List<bool> dp = List.filled(n + 1, false);

    dp[0] = true;

    for (int i = 1; i <= n; i++) {
      for (int j = 0; j < i; j++) {
        if (dp[j] && wordSet.contains(s.substring(j, i))) {
          dp[i] = true;
          break;
        }
      }
    }

    return dp[n];
  }
}
