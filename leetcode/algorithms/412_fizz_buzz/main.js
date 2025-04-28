/**
 * @param {number} n
 * @return {string[]}
 */
var fizzBuzz = function (n) {
  const result = new Array();

  for (let i = 1; i <= n; i++) {
    if (i % 3 === 0 && i % 5 === 0) {
      result.push("FizzBuzz");
    } else if (i % 3 === 0) {
      result.push("Fizz");
    } else if (i % 5 === 0) {
      result.push("Buzz");
    } else {
      result.push(`${i}`);
    }
  }

  return result;
};


// Solution
var solution = function (n) {
  return new Array(n)
    .fill(0)
    .map((a, i) => (++i % 3 ? "" : "Fizz") + (i % 5 ? "" : "Buzz") || "" + i);
};
