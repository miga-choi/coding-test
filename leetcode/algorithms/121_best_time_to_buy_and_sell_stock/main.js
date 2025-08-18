/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {number[]} prices
 * @return {number}
 */
var maxProfit = function (prices) {
  let minPrice = 100000;
  let maxProfit = 0;

  for (const price of prices) {
    if (price < minPrice) {
      minPrice = price;
    }

    const profit = price - minPrice;
    if (profit > maxProfit) {
      maxProfit = diff;
    }
  }

  return maxProfit;
};


// Solution
/**
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {number[]} prices
 * @return {number}
 */
const solution = (prices) => {
  if (prices.length < 2) {
    return 0;
  }

  let minPrice = Infinity;
  let maxProfit = 0;

  for (let i = 0; i < prices.length; i++) {
    const currentPrice = prices[i];

    if (currentPrice < minPrice) {
      minPrice = currentPrice;
    } else if (currentPrice - minPrice > maxProfit) {
      maxProfit = currentPrice - minPrice;
    }
  }

  return maxProfit;
};
