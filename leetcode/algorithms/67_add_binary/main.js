/**
 * Reverse Iteration
 *
 * Complexities:
 *   N - Length of `a`
 *   M - Length of `b`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(max(N, M))
 */
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
  const count = Math.abs(a.length - b.length);

  for (let i = 0; i < count; i++) {
    if (a.length > b.length) {
      b = "0".concat(b);
    } else {
      a = "0".concat(a);
    }
  }

  let result = "";
  let up = 0;

  for (let i = a.length - 1; i >= 0; i--) {
    let num = parseInt(a[i]) + parseInt(b[i]) + up;
    up = 0;
    if (num > 1) {
      num = num - 2;
      up = 1;
    }
    result = String(num).concat(result);
  }

  if (up > 0) {
    result = String(up).concat(result);
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Reverse
 *
 * Complexities:
 *   N - Length of `a`
 *   M - Length of `b`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(max(N, M))
 */
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var solution1 = function (a, b) {
  let result = [];
  let i = a.length - 1;
  let j = b.length - 1;
  let carry = 0;

  while (i >= 0 || j >= 0 || carry > 0) {
    const digitA = i >= 0 ? parseInt(a[i]) : 0;
    const digitB = j >= 0 ? parseInt(b[j]) : 0;

    const sum = digitA + digitB + carry;

    result.push(sum % 2);

    carry = Math.floor(sum / 2);

    i--;
    j--;
  }

  return result.reverse().join("");
};

/**
 * Solution 2
 *
 * Built-in function
 *
 * Complexities:
 *   N - Length of `a`
 *   M - Length of `b`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(max(N, M))
 */
/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var solution2 = function (a, b) {
  return (BigInt(`0b${a}`) + BigInt(`0b${b}`)).toString(2);
};
