from collections import deque
from typing import List


class CoinChange:
    """
    # DP (Dynamic Programming)
    #
    # Complexities:
    #   N - The size of `coins`
    #   M - `amount`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(N)
    """
    def coinChange(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        dp = [10e4 + 1] * (amount + 1)
        dp[0] = 0

        for i in range(amount + 1):
            for j in range(len(coins)):
                coin: int = coins[j]
                if i >= coin:
                    dp[i] = min(dp[i], dp[i - coin] + 1)

        if dp[amount] > amount:
            return -1
        else:
            return dp[amount]


    # Solution
    """
    # Solution 1
    #
    # DP (Dynamic Programming)
    #
    # Complexities:
    #   N - The size of `coins`
    #   M - `amount`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(N)
    """
    def solution1(self, coins: List[int], amount: int) -> int:
        INF = amount + 1
        dp = [INF] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for c in coins:
                if c <= i:
                    dp[i] = min(dp[i], dp[i - c] + 1)

        return dp[amount] if dp[amount] != INF else -1

    """
    # Solution 2
    #
    # BFS
    #
    # Complexities:
    #   N - The size of `coins`
    #   M - `amount`
    #   - Time Complexity: O(N * M)
    #   - Space Complexity: O(N)
    """
    def solution2(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        visited = {amount}
        queue = deque([(amount, 0)])

        while queue:
            remain, steps = queue.popleft()

            for c in coins:
                nxt = remain - c

                if nxt == 0:
                    return steps + 1

                if nxt > 0 and nxt not in visited:
                    visited.add(nxt)
                    queue.append((nxt, steps + 1))

        return -1
