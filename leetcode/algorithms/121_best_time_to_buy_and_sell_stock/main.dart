import 'dart:math';

class BestTimeToBuyAndSellStock {
  /**
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  int maxProfit(List<int> prices) {
    int minPrice = 100000;
    int maxProfit = 0;

    for (final int price in prices) {
      if (price < minPrice) {
        minPrice = price;
      }

      int profit = price - minPrice;
      if (profit > maxProfit) {
        maxProfit = profit;
      }
    }

    return maxProfit;
  }


  // Solution
  /**
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  int solution(List<int> prices) {
    if (prices.length < 2) {
      return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.length; i++) {
      int currentPrice = prices[i];

      int currentProfit = currentPrice - minPrice;
      maxProfit = max(maxProfit, currentProfit);

      minPrice = min(minPrice, currentPrice);
    }

    return maxProfit;
  }
}
