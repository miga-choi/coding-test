import 'dart:math';

class BestTimeToBuyAndSellStock {
  int maxProfit(List<int> prices) {
    int minPrice = 10000;
    int price = 0;
    for (int i = 0; i < prices.length; i++) {
      if (prices[i] < minPrice) {
        minPrice = prices[i];
      }
      if (prices[i] - minPrice > price) {
        price = prices[i] - minPrice;
      }
    }
    return price;
  }

  // Best Solution
  int bestSolution(List<int> prices) {
    int profit = 0;
    int minPrice = prices.first;
    for (int i = 1; i < prices.length; i++) {
      minPrice = min(minPrice, prices[i]);
      profit = max(profit, prices[i] - minPrice);
    }
    return profit;
  }
}
