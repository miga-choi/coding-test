/**
 * String Conversion (Binary String Flip)
 *
 * Complexities:
 *   N - The Bit Length of `num`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
  const binary = num.toString(2).split("");
  let result = "";

  for (const i of binary) {
    if (i === "1") {
      result += "0";
    } else {
      result += "1";
    }
  }

  return parseInt(result, 2);
};


// Solution
/**
 * Solution 1
 *
 * Bit-by-Bit Construction
 *
 * Complexities:
 *   N - The Bit Length of `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution1 = function (num) {
  let result = 0;
  let bit = 0;

  while (num > 0) {
    if ((num & 1) === 0) {
      result |= 1 << bit;
    }
    num >>= 1;
    bit++;
  }

  return result;
};

/**
 * Solution 2
 *
 * Bit Mask + XOR
 *
 * Complexities:
 *   N - The Bit Length of `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution2 = function (num) {
  let mask = 1;

  while (mask < num) {
    mask = (mask << 1) | 1;
  }

  return num ^ mask;
};

/**
 * Solution 3
 *
 * Bit Smearing (Highest Bit Propagation)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution3 = function (num) {
  let mask = num;
  mask |= mask >> 1;
  mask |= mask >> 2;
  mask |= mask >> 4;
  mask |= mask >> 8;
  mask |= mask >> 16;
  return num ^ mask;
};

/**
 * Solution 4
 *
 * Count Leading Zeros (Math.clz32)
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution4 = function (num) {
  const mask = -1 >>> Math.clz32(num);
  return num ^ mask;
};

/**
 * Solution 5
 *
 * String Conversion
 *
 * Complexities:
 *   N - The Bit Length of `num`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number} num
 * @return {number}
 */
var solution5 = function (num) {
  const flipped = num
    .toString(2)
    .split("")
    .map((c) => (c === "1" ? "0" : "1"))
    .join("");
  return parseInt(flipped, 2);
};
