/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfThree = function (n) {
  if ((Math.log10(n) / Math.log10(3)) % 1 === 0) {
    return true;
  }
  return false;
};


// Solution
// Solution 1: Logarithms
var solution1 = function (n) {
  let a = Math.log(n) / Math.log(3);
  return Math.abs(a - Math.round(a)) < 1e-10;
};

// Solution 2: Modulo
var solution2 = function (n) {
  return n > 0 && 1162261467 % n === 0;
};
