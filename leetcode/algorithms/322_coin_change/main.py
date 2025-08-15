from typing import List


class CoinChange:
    ##
    # DP (Dynamic Programming)
    # - Time Complexity: O(M * N)
    # - Space Complexity: O(N)
    #
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
    ##
    # DP (Dynamic Programming)
    # - Time Complexity: O(M * N)
    # - Space Complexity: O(N)
    #
    def solution(self, coins: List[int], amount: int) -> int:
        if amount == 0:
            return 0

        dp = [-1] * (amount + 1)
        dp[0] = 0

        for i in range(1, amount + 1):
            for coin in coins:
                if i < coin:
                    continue
                if dp[i] != -1 and dp[i - coin] != -1:
                    dp[i] = min(dp[i], dp[i - coin] + 1)
                else:
                    if dp[i - coin] != -1:
                        dp[i] = dp[i - coin] + 1

        return dp[amount]
