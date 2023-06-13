/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
  const nString = n.toString(2);
  let result = 0;
  for (const c of nString) {
    if (c === '1') {
      result++;
    }
  }
  return result;
};

// Best Solution
// Loop through a string
var bestSolution1 = function (int) {
  const str = int.toString(2); // pass a radix parameter of 2 to keep it in base 2.
  let count = 0;
  for (let char of str) {
    if (char === '1') count++;
  }
  return count;
};

// Filter an array of strings
var bestSolution2 = function (int) {
  return int
    .toString(2)
    .split('')
    .filter((char) => char === '1').length;
};

// String matching
var bestSolution3 = function (int) {
  const str = int.toString(2);
  return str === '0' ? 0 : str.match(/1/g).length;
};

// Convert to string, replace zeroes
var bestSolution4 = function (int) {
  return int.toString(2).replaceAll('0', '').length;
};

// While loop with integer manipulation
var bestSolution5 = function (int) {
  let count = 0;
  while (int !== 0) {
    const bitComparison = int & 1; // 1 & 1 will return 1. 0 & 1 will return 0.
    if (bitComparison === 1) count++;
    int >>>= 1; // unsigned right shift assignment (chop off the last bit and assign it)
  }
  return count;
};
