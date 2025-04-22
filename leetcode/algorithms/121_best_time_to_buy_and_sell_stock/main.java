class BestTimeToBuyAndSellStock {
  public int maxProfit(int[] prices) {
    int buy = 0;
    int profit = 0;

    for (int sell = 1; sell < prices.length; sell++) {
      if (prices[sell] > prices[buy]) {
        if (prices[sell] - prices[buy] > profit) {
          profit = prices[sell] - prices[buy];
        }
      } else {
        buy = sell;
      }
    }

    return profit;
  }


  // Solution
  public int solution(int[] prices) {
    int lsf = Integer.MAX_VALUE;
    int op = 0;
    int pist = 0;

    for (int i = 0; i < prices.length; i++) {
      if (prices[i] < lsf) {
        lsf = prices[i];
      }
      pist = prices[i] - lsf;
      if (op < pist) {
        op = pist;
      }
    }
    return op;
  }
}
