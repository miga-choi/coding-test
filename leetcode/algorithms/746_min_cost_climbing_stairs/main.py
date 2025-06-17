from typing import List


class MinCostClimbingStairs:
    def minCostClimbingStairs(self, cost: List[int]) -> int:
        size: int = len(cost)

        dp: List[int] = [0] * size

        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2, size):
            dp[i] = cost[i] + min(dp[i - 1], dp[i - 2])

        return min(dp[size - 1], dp[size - 2])


    # Solution
    def solution(self, cost: List[int]) -> int:
        first: int = cost[0]
        second: int = cost[1]

        for i in range(2, len(cost)):
            curr: int = cost[i] + min(first, second)
            first = second
            second = curr

        return min(first, second)
