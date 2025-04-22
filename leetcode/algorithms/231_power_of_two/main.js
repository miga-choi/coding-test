/**
 * @param {number} n
 * @return {boolean}
 */
var isPowerOfTwo = function (n) {
  let m = 0;

  while (2 ** m <= n) {
    if (2 ** m === n) {
      return true;
    }
    m++;
  }

  return false;
};


// Solution
let solution = (n) => (n > 0 ? !(n & (n - 1)) : false);
