/**
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let buy = 0;
  let profit = 0;
  for (let sell = 1; sell < prices.length; sell++) {
    if (prices[sell] > prices[buy]) {
      if (prices[sell] - prices[buy] > profit) {
        profit = prices[sell] - prices[buy];
      }
    } else {
      buy = sell;
    }
  }
  return profit;
};


// Solution
const solution = (prices) => {
  let left = 0; // Buy
  let right = 1; // sell
  let max_profit = 0;
  while (right < prices.length) {
    if (prices[left] < prices[right]) {
      let profit = prices[right] - prices[left]; // our current profit
      max_profit = Math.max(max_profit, profit);
    } else {
      left = right;
    }
    right++;
  }
  return max_profit;
};
