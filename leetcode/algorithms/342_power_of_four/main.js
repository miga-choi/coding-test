/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfFour = function (n) {
  if ((Math.log10(n) / Math.log10(4)) % 1 === 0) {
    return true;
  }
  return false;
};


// Solution
var solution = (n) => n > 0 && Math.log2(n) % 2 === 0;
