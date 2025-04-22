/**
 * @param {number} n
 * @return {boolean}
 */
var canWinNim = function (n) {
  if (n % 4 === 0) {
    return false;
  }
  return true;
};


// Solution
// Solution 1
var solution1 = function (n) {
  if (memo[n] === undefined) {
    memo[n] = !solution1(n - 3) || !solution1(n - 2) || !solution1(n - 1);
  }
  return memo[n];
};

// Solution 2
var solution2 = function (n) {
  n %= 4;
  if (memo[n] === undefined) {
    memo[n] = !solution2(n - 3) || !solution2(n - 2) || !solution2(n - 1);
  }
  return memo[n];
};

// Solution 3
var solution3 = function (n) {
  if (n % 4 == 0) {
    return false;
  } else {
    return true;
  }
};
