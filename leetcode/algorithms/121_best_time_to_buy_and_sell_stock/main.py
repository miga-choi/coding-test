class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        buy = 0
        profit = 0

        for sell in range(1, len(prices)):
            if prices[sell] > prices[buy]:
                if prices[sell] - prices[buy] > profit:
                    profit = prices[sell] - prices[buy]
            else:
                buy = sell

        return profit

    # Best Solution
    def bestSolution(self, prices: List[int]) -> int:
        if not prices:
            return 0

        maxProfit = 0
        minPurchase = prices[0]
        for i in range(1, len(prices)):
            maxProfit = max(maxProfit, prices[i] - minPurchase)
            minPurchase = min(minPurchase, prices[i])
        return maxProfit
