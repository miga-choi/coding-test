/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {string}
 */
var toHex = function (num) {
  const hex = [
    "0",
    "1",
    "2",
    "3",
    "4",
    "5",
    "6",
    "7",
    "8",
    "9",
    "a",
    "b",
    "c",
    "d",
    "e",
    "f",
  ];

  if (num == 0) {
    return "0";
  }

  if (num < 0) {
    num += Math.pow(2, 32);
  }

  let result = "";

  while (num > 0) {
    const remainder = num % 16;
    result = hex[remainder] + result;
    num = Math.floor(num / 16);
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Bitwise Operation
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {string}
 */
var solution1 = function (num) {
  if (num === 0) {
    return "0";
  }

  const digits = "0123456789abcdef";
  let result = "";

  while (num !== 0) {
    result = digits[num & 15] + result;
    num >>>= 4;
  }

  return result;
};

/**
 * Solution 2
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {string}
 */
var solution2 = function (num) {
  if (num === 0) {
    return "0";
  }

  const digits = "0123456789abcdef";
  const result = [];

  while (num !== 0) {
    result.push(digits[num & 15]);
    num >>>= 4;
  }

  return result.reverse().join("");
};

/**
 * Solution 3
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {string}
 */
var solution3 = function (num) {
  const digits = "0123456789abcdef";
  let result = "";

  for (let shift = 28; shift >= 0; shift -= 4) {
    const d = (num >>> shift) & 15;

    if (result === "" && d === 0) {
      continue;
    }

    result += digits[d];
  }

  return result || "0";
};

/**
 * Solution 4
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {string}
 */
var solution4 = function (num) {
  if (num === 0) {
    return "0";
  }

  if (num < 0) {
    num += 2 ** 32;
  }

  const digits = "0123456789abcdef";
  let result = "";

  while (num > 0) {
    result = digits[num % 16] + result;
    num = Math.floor(num / 16);
  }

  return result;
};
