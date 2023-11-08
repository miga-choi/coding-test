/**
 * @param {number} n
 * @return {number}
 */
var fib = function (n) {
  if (n === 0) {
    return 0;
  } else if (n === 1) {
    return 1;
  } else {
    return fib(n - 1) + fib(n - 2);
  }
};


// Best Solution
// Binet's formula
var bestSolution1 = function (n) {
  let sqrt5 = Math.sqrt(5);
  return (Math.pow(1 + sqrt5, n) - Math.pow(1 - sqrt5, n)) / Math.pow(2, n) / sqrt5;
};

// O(N) iteration
var bestSolution2 = function (n) {
  if (n < 2) {
    return n;
  }
  let a = 0, b = 1;
  for (let i = 1; i < n; i++) {
    [a, b] = [b, a + b];
  }
  return b;
};
