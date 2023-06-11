/**
 * @param {number} n - a positive integer
 * @return {number} - a positive integer
 */
var reverseBits = function (n) {
  n = n.toString(2).split('').reverse();

  while (n.length < 32) {
    n.push('0');
  }

  return parseInt(n.toString().replaceAll(',', ''), 2);
};

// Best Solution
var bestSolution = function (n) {
  var result = 0;
  var count = 32;

  while (count--) {
    result *= 2;
    result += n & 1;
    n = n >> 1;
  }
  return result;
};
