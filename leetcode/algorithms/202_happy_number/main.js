/**
 * Hash Set
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
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
    n = nString.split("").reduce((total_, current_) => {
      return parseInt(total_) + Math.pow(parseInt(current_), 2);
    }, 0);
    if (n === 1) {
      return true;
    }
  }

  return n === 1;
};


// Solution
/**
 * Solution 1
 *
 * Floyd's Cycle-Finding Algorithm
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number} n
 * @return {number}
 */
function getNext1(n) {
  let totalSum = 0;

  while (n > 0) {
    const digit = n % 10;
    totalSum += digit * digit;
    n = Math.floor(n / 10);
  }

  return totalSum;
}

/**
 * @param {number} n
 * @return {boolean}
 */
var solution1 = function (n) {
  const seen = new Set();

  while (n !== 1 && !seen.has(n)) {
    seen.add(n);
    n = getNext1(n);
  }

  return n === 1;
};

/**
 * Solution 2
 *
 * Hash Set
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {number}
 */
function getNext2(n) {
  let totalSum = 0;

  while (n > 0) {
    const digit = n % 10;
    totalSum += digit * digit;
    n = Math.floor(n / 10);
  }

  return totalSum;
}

/**
 * @param {number} n
 * @return {boolean}
 */
var solution2 = function (n) {
  let slow = n;
  let fast = getNext2(n);

  while (fast !== 1 && slow !== fast) {
    slow = getNext2(slow);
    fast = getNext2(getNext2(fast));
  }

  return fast === 1;
};
