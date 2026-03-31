import math
from typing import List


class UniquePaths:
    """
    # DP
    #
    # Complexities:
    #   M - `m`
    #   N - `n`
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(N)
    """
    def uniquePaths(self, m: int, n: int) -> int:
        dp: List[int] = [1] * n

        for _ in range(1, m):
            for j in range(1, n):
                dp[j] = dp[j] + dp[j - 1]

        return dp[n - 1]


    # Solution
    """
    # Solution 1
    #
    # DP
    #
    # Complexities:
    #   M - `m`
    #   N - `n`
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(M * N)
    """
    def solution1(self, m: int, n: int) -> int:
        dp = [[1] * n for _ in range(m)]

        for i in range(1, m):
            for j in range(1, n):
                dp[i][j] = dp[i-1][j] + dp[i][j-1]

        return dp[m-1][n-1]

    """
    # Solution 2
    #
    # DP
    #
    # Complexities:
    #   M - `m`
    #   N - `n`
    #   - Time Complexity: O(M * N)
    #   - Space Complexity: O(N)
    """
    def solution2(self, m: int, n: int) -> int:
        dp = [1] * n

        for i in range(1, m):
            for j in range(1, n):
                dp[j] += dp[j-1]

        return dp[-1]

    """
    # Solution 3
    #
    # Combinatorics
    #
    # Complexities:
    #   M - `m`
    #   N - `n`
    #   - Time Complexity: O(min(M, N))
    #   - Space Complexity: O(1)
    """
    def solution3(self, m: int, n: int) -> int:
        total_steps = m + n - 2
        down_steps = m - 1

        return math.comb(total_steps, down_steps)
