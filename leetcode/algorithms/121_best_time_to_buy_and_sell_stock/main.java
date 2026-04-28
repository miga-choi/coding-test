class BestTimeToBuyAndSellStock {
  /**
   * Greedy
   *
   * Complexities:
   *   N - Size of `prices`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int maxProfit(int[] prices) {
    int minPrice = 100000;
    int maxProfit = 0;

    for (int price : prices) {
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
  public int solution(int[] prices) {
    if (prices == null || prices.length <= 1) {
      return 0;
    }

    int minPrice = Integer.MAX_VALUE;
    int maxProfit = 0;

    for (int price : prices) {
      if (price < minPrice) {
        minPrice = price;
      } else if (price - minPrice > maxProfit) {
        maxProfit = price - minPrice;
      }
    }

    return maxProfit;
  }
}
