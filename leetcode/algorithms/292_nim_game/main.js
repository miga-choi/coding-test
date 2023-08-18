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


// Best Solution
var bestSolution1 = function (n) {
  if (memo[n] === undefined) {
    memo[n] = !bestSolution1(n - 3) || !bestSolution1(n - 2) || !bestSolution1(n - 1);
  }
  return memo[n];
};

var bestSolution2 = function (n) {
  n %= 4;
  if (memo[n] === undefined) {
    memo[n] = !bestSolution2(n - 3) || !bestSolution2(n - 2) || !bestSolution2(n - 1);
  }
  return memo[n];
};

var bestSolution3 = function (n) {
  if (n % 4 == 0) return false;
  else return true;
};
