from typing import List


class BestTimeToBuyAndSellStock:
    """
    # Greedy
    #
    # Complexities:
    #   N - Size of `prices`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
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
    """
    # Greedy
    #
    # Complexities:
    #   N - Size of `prices`
    #   - Time Complexity: O(N)
    #   - Space Complexity: O(1)
    """
    def solution(self, prices: List[int]) -> int:
        min_price = float('inf')
        max_profit = 0

        for price in prices:
            if price < min_price:
                min_price = price
            elif price - min_price > max_profit:
                max_profit = price - min_price

        return max_profit
