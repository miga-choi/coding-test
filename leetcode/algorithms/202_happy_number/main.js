/**
 * @param {number} n
 * @return {boolean}
 */
var isHappy = function (n) {
  const set = {};
  while (n > 1) {
    let nString = n.toString();
    if (set[nString]) {
      return false;
    }
    set[nString] = true;
    n = nString.split('').reduce((total_, current_) => {
      return parseInt(total_) + Math.pow(parseInt(current_), 2);
    }, 0);
    if (n === 1) {
      return true;
    }
  }
  return n === 1;
};

// Best Solution
var bestSolution1 = function (n) {
  var seen = {};
  while (n !== 1 && !seen[n]) {
    seen[n] = true;
    n = sumOfSquares(n);
  }
  return n === 1 ? true : false;
};

function sumOfSquares(numString) {
  return numString
    .toString()
    .split('')
    .reduce(function (sum, num) {
      return sum + Math.pow(num, 2);
    }, 0);
}

var bestSolution2 = function (n) {
  if (n < 10) {
    if (n === 1 || n === 7) {
      return true;
    }
    return false;
  }
  let total = 0;
  while (n > 0) {
    let sq = n % 10;
    total += sq ** 2;
    n -= sq;
    n /= 10;
  }
  if (total === 1) {
    return true;
  }
  return isHappy(total);
};
