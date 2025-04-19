/**
 * @param {number} n - a positive integer
 * @return {number}
 */
var hammingWeight = function (n) {
  const nString = n.toString(2);
  let result = 0;
  for (const c of nString) {
    if (c === "1") {
      result++;
    }
  }
  return result;
};


// Solution
// Solution 1: Loop through a string
var solution1 = function (int) {
  // pass a radix parameter of 2 to keep it in base 2.
  const str = int.toString(2);

  let count = 0;

  for (let char of str) {
    if (char === "1") count++;
  }

  return count;
};

// Solution 2: Filter an array of strings
var solution2 = function (int) {
  return int
    .toString(2)
    .split("")
    .filter((char) => char === "1").length;
};

// Solution 3: String matching
var solution3 = function (int) {
  const str = int.toString(2);
  return str === "0" ? 0 : str.match(/1/g).length;
};

// Solution 4: Convert to string, replace zeroes
var solution4 = function (int) {
  return int.toString(2).replaceAll("0", "").length;
};

// Solution 5: While loop with integer manipulation
var solution5 = function (int) {
  let count = 0;
  while (int !== 0) {
    // 1 & 1 will return 1. 0 & 1 will return 0.
    const bitComparison = int & 1;

    if (bitComparison === 1) {
      count++;
    }

    // unsigned right shift assignment (chop off the last bit and assign it)
    int >>>= 1;
  }
  return count;
};
