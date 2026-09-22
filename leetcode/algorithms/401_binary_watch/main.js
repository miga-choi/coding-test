/**
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var readBinaryWatch = function (turnedOn) {
  const result = [];

  // Hour
  for (let h = 0; h < 12; h++) {
    // Minute
    for (let m = 0; m < 60; m++) {
      const hCount = h.toString(2).replaceAll("0", "").length;
      const mCount = m.toString(2).replaceAll("0", "").length;
      if (hCount + mCount === turnedOn) {
        result.push(`${h}:${m > 9 ? m : `0${m}`}`);
      }
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var solution1 = function (turnedOn) {
  const bitCount = (x) => {
    let count = 0;

    while (x) {
      x &= x - 1;
      count++;
    }

    return count;
  };

  const result = [];

  for (let h = 0; h < 12; h++) {
    for (let m = 0; m < 60; m++) {
      if (bitCount(h) + bitCount(m) === turnedOn) {
        result.push(`${h}:${m < 10 ? "0" : ""}${m}`);
      }
    }
  }

  return result;
};

/**
 * Solution 2
 *
 * DP
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var solution2 = function (turnedOn) {
  const bits = new Array(60).fill(0);
  for (let i = 1; i < 60; i++) {
    bits[i] = bits[i >> 1] + (i & 1);
  }

  const result = [];
  for (let h = 0; h < 12; h++) {
    for (let m = 0; m < 60; m++) {
      if (bits[h] + bits[m] === turnedOn) {
        result.push(`${h}:${m < 10 ? "0" : ""}${m}`);
      }
    }
  }

  return result;
};

/**
 * Solution 3
 *
 * 10-Bitmask
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var solution3 = function (turnedOn) {
  const result = [];

  for (let mask = 0; mask < 1024; mask++) {
    const h = mask >> 6;
    const m = mask & 0b111111;

    if (h >= 12 || m >= 60) {
      continue;
    }

    let count = 0,
      x = mask;
    while (x) {
      x &= x - 1;
      count++;
    }

    if (count === turnedOn) {
      result.push(`${h}:${m < 10 ? "0" : ""}${m}`);
    }
  }

  return result;
};

/**
 * Solution 4
 *
 * Backtracking
 *
 * Complexities:
 *   - Time Complexity: O(1)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} turnedOn
 * @return {string[]}
 */
var solution4 = function (turnedOn) {
  const hours = [8, 4, 2, 1];
  const minutes = [32, 16, 8, 4, 2, 1];
  const result = [];

  const backtrack = (idx, remaining, h, m) => {
    if (h >= 12 || m >= 60) {
      return;
    }

    if (remaining === 0) {
      result.push(`${h}:${m < 10 ? "0" : ""}${m}`);
      return;
    }

    for (let i = idx; i < 10; i++) {
      if (i < 4) {
        backtrack(i + 1, remaining - 1, h + hours[i], m);
      } else {
        backtrack(i + 1, remaining - 1, h, m + minutes[i - 4]);
      }
    }
  };

  backtrack(0, turnedOn, 0, 0);
  return result;
};
