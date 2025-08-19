from typing import List


class BestTimeToBuyAndSellStock:
    ##
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def maxProfit(self, prices: List[int]) -> int:
        minPrice: int = 100000
        maxProfit: int = 0

        for price in prices:
            if price < minPrice:
                minPrice = price

            profit: int = price - minPrice
            if profit > maxProfit:
                maxProfit = profit

        return maxProfit


    # Solution
    ##
    # - Time Complexity: O(N)
    # - Space Complexity: O(1)
    #
    def solution(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0

        for price in prices:
            min_price = min(min_price, price)
            max_profit = max(max_profit, price - min_price)

        return max_profit
