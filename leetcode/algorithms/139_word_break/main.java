import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Set;

class WordBreak {
    /**
     * Dynamic Programming
     *
     * Complexities:
     *   N - Size of `s`
     *   - Time Complexity: O(N³)
     *   - Space Complexity: O(N)
     */
    public boolean wordBreak(String s, List<String> wordDict) {
        int sLen = s.length();

        Set<String> dict = new HashSet<>(wordDict);

        boolean[] dp = new boolean[sLen + 1];
        Arrays.fill(dp, false);

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
    public boolean solution(String s, List<String> wordDict) {
        Set<String> wordSet = new HashSet<>(wordDict);

        int n = s.length();
        boolean[] dp = new boolean[n + 1];

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
