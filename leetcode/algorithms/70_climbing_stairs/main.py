from typing import List


class ClimbingStairs:
    """
    # DP (Dynamic Programming) with Array
    #
    # Complexities:
    #   N - Value of `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def climbStairs(self, n: int) -> int:
        if n < 3:
            return n

        dp: List[int] = [0] * (n + 1)
        dp[0] = 0
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]


    # Solution
    """
    # Solution 1
    #
    # Recursion
    #
    # Complexities:
    #   N - Value of `n`
    #   - Time Complexity: O(2ᴺ)
    #   - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> int:
        if n <= 2:
            return n

        return self.solution1(n-1) + self.solution1(n-2)

    """
    # Solution 2
    #
    # DP (Dynamic Programming)
    #
    # Complexities:
    #   N - Value of `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution2(self, n: int) -> int:
        if n <= 2:
            return n

        prev2, prev1 = 1, 2

        for _ in range(3, n + 1):
            current = prev1 + prev2

            prev2 = prev1
            prev1 = current

        return prev1

    """
    # Solution 3
    #
    # DP (Dynamic Programming) with Array
    #
    # Complexities:
    #   N - Value of `n`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(N)
    """
    def solution3(self, n: int) -> int:
        if n <= 2:
            return n

        dp = [0] * (n + 1)
        dp[1], dp[2] = 1, 2

        for i in range(3, n + 1):
            dp[i] = dp[i-1] + dp[i-2]

        return dp[n]
