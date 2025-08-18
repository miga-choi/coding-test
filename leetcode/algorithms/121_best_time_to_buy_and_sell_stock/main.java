class BestTimeToBuyAndSellStock {
  /**
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
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
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public int solution(int[] prices) {
    if (prices == null || prices.length < 2) {
      return 0;
    }

    int minPrice = Integer.MAX_VALUE;
    int maxProfit = 0;

    for (int currentPrice : prices) {
      if (currentPrice < minPrice) {
        minPrice = currentPrice;
      } else {
        int potentialProfit = currentPrice - minPrice;
        maxProfit = Math.max(maxProfit, potentialProfit);
      }
    }

    return maxProfit;
  }
}
