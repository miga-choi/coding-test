/**
 * @param {number} n
 * @return {boolean}
 */
var isPrime = function (n) {
  if (n < 2) {
    return 0;
  }

  for (let i = 2; i < n; i++) {
    if (n % i == 0) {
      return 0;
    }
  }

  return 1;
};

/**
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var countPrimeSetBits = function (left, right) {
  let count = 0;

  for (let i = left; i <= right; i++) {
    let bits = 0;
    let n = i;

    while (n > 0) {
      bits += n % 2;
      n = Math.floor(n / 2);
    }

    if (isPrime(bits)) {
      count++;
    }
  }

  return count;
};


// Solution
var countPrimeSetBits = function (left, right) {
  let count = 0;
  while (left <= right) {
    count += (665772 >> left.toString(2).match(/1/g).length) & 1;
    left++;
  }
  return count;
};
