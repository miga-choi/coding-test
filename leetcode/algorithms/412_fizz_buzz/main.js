/**
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
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
/**
 * Solution 1
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {string[]}
 */
var solution1 = function (n) {
  const result = new Array(n);

  for (let i = 1; i <= n; i++) {
    if (i % 15 === 0) {
      result[i - 1] = "FizzBuzz";
    } else if (i % 3 === 0) {
      result[i - 1] = "Fizz";
    } else if (i % 5 === 0) {
      result[i - 1] = "Buzz";
    } else {
      result[i - 1] = String(i);
    }
  }

  return result;
};

/**
 * Solution 2
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {string[]}
 */
var solution2 = function (n) {
  const result = [];

  for (let i = 1; i <= n; i++) {
    let s = "";

    if (i % 3 === 0) {
      s += "Fizz";
    }
    if (i % 5 === 0) {
      s += "Buzz";
    }

    result.push(s || String(i));
  }

  return result;
};

/**
 * Solution 3
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {string[]}
 */
var solution3 = function (n) {
  const rules = [
    [3, "Fizz"],
    [5, "Buzz"],
  ];

  const result = [];

  for (let i = 1; i <= n; i++) {
    let s = "";

    for (const [divisor, word] of rules) {
      if (i % divisor === 0) {
        s += word;
      }
    }

    result.push(s || String(i));
  }

  return result;
};

/**
 * Solution 4
 *
 * Complexities:
 *   N - `n`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} n
 * @return {string[]}
 */
var solution4 = function (n) {
  const result = [];
  let fizz = 0,
    buzz = 0;

  for (let i = 1; i <= n; i++) {
    fizz++;
    buzz++;
    let s = "";

    if (fizz === 3) {
      s += "Fizz";
      fizz = 0;
    }
    if (buzz === 5) {
      s += "Buzz";
      buzz = 0;
    }

    result.push(s || String(i));
  }

  return result;
};
