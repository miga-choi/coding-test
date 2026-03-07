from typing import List, Set


class WordBreak:
    """
    # Dynamic Programming
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N³)
    #   - Space Complexity: O(N)
    """
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        s_len: int = len(s)

        dict: Set[str] = set(wordDict)

        dp: List[bool] = [False] * (s_len + 1)
        dp[0] = True

        for i in range(1, s_len + 1):
            for j in range(0, i):
                if dp[j] and s[j:i] in dict:
                    dp[i] = True
                    break

        return dp[s_len]


    # Solution
    """
    # Dynamic Programming
    #
    # Complexities:
    #   N - Size of `s`
    #   - Time Complexity: O(N³)
    #   - Space Complexity: O(N)
    """
    def solution(self, s: str, wordDict: List[str]) -> bool:
        word_set = set(wordDict)
        n = len(s)

        dp = [False] * (n + 1)
        dp[0] = True

        for i in range(1, n + 1):
            for j in range(i):
                if dp[j] and s[j:i] in word_set:
                    dp[i] = True
                    break

        return dp[n]
