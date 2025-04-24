/**
 * @param {number} n
 * @return {boolean}
 */
var hasAlternatingBits = function (n) {
  let prev = -1;

  while (n > 0) {
    if (n % 2 === prev) {
      return false;
    }
    prev = n % 2;
    n >>= 1;
  }

  return true;
};


// Solution
var solution = function (n) {
  // Converting into binary string
  let binary = n.toString(2);

  for (let i = 1; i < binary.length; i++) {
    if (binary[i - 1] === binary[i]) {
      return false;
    }
  }

  return true;
};
