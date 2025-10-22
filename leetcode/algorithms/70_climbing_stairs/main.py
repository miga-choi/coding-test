from typing import List


class ClimbingStairs:
    """
    # DP (Dynamic Programming)
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
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
    # Recursion (Time Limit Exceeded)
    # - Time Complexity: O(2ᴺ)
    # - Space Complexity: O(1)
    """
    def solution1(self, n: int) -> int:
        if n <= 2:
            return n
        return self.solution1(n - 1) + self.solution1(n - 2)

    """
    # Solution 2
    #
    # DP (Dynamic Programming): Top-down with Memoization
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    """
    def solution2(self, n: int) -> int:
        memo = {}

        def solve(k: int) -> int:
            if k in memo:
                return memo[k]

            if k <= 2:
                return k

            memo[k] = solve(k - 1) + solve(k - 2)

            return memo[k]

        return solve(n)

    """
    # Solution 3
    #
    # DP (Dynamic Programming): Bottom-up with Tabulation
    # - Time Complexity: O(N)
    # - Space Complexity: O(N)
    """
    def solution3(self, n: int) -> int:
        if n <= 2:
            return n

        dp = [0] * (n + 1)
        dp[1] = 1
        dp[2] = 2

        for i in range(3, n + 1):
            dp[i] = dp[i - 1] + dp[i - 2]

        return dp[n]

    """
    # Solution 4
    #
    # DP (Dynamic Programming): Space Optimization
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    """
    def solution4(self, n: int) -> int:
        if n <= 2:
            return n
            
        two_steps_back, one_step_back = 1, 2
        
        for _ in range(3, n + 1):
            current_step = one_step_back + two_steps_back

            two_steps_back = one_step_back
            one_step_back = current_step
            
        return one_step_back