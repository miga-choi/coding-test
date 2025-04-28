/**
 * @param {number} n
 * @return {number}
 */
var arrangeCoins = function (n) {
  for (i = 1; i > 0; i++) {
    n -= i;
    if (n === 0) {
      return i;
    } else if (n < 0) {
      return i - 1;
    }
  }
};


// Solution
var solution = function (n) {
  let stairs = 0;

  while (stairs <= n) {
    n -= stairs;
    stairs++;
  }

  return stairs - 1;
};
