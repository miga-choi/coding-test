import 'dart:math';

class BestTimeToBuyAndSellStock {
  /**
   * Greedy
   *
   * Complexities:
   *   N - Size of `prices`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
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
   * Greedy
   *
   * Complexities:
   *   N - Size of `prices`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution(List<int> prices) {
    if (prices.isEmpty) {
      return 0;
    }

    int minPrice = prices[0];
    int maxProfit = 0;

    for (int i = 1; i < prices.length; i++) {
      int currentPrice = prices[i];

      maxProfit = max(maxProfit, currentPrice - minPrice);

      minPrice = min(minPrice, currentPrice);
    }

    return maxProfit;
  }
}
