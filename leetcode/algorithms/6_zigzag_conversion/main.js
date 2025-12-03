/**
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 *
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var convert = function (s, numRows) {
  const sLen = s.length;

  if (numRows == 1 || numRows > sLen) {
    return s;
  }

  const cycleLen = numRows * 2 - 2;
  let result = "";
  for (let row = 0; row < numRows; row++) {
    for (let cycle = row; cycle < sLen; cycle += cycleLen) {
      result += s[cycle];

      if (row > 0 && row < numRows - 1) {
        const diag_idx = cycle + cycleLen - row * 2;
        if (diag_idx < sLen) {
          result += s[diag_idx];
        }
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
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 *
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var solution1 = function (s, numRows) {
  if (numRows == 1 || numRows >= s.length) {
    return s;
  }

  const rows = new Array(numRows).fill(new Array(1).fill(""));

  let currentRow = 0;
  let goingDown = false;

  for (const c of s) {
    rows[currentRow] += c;

    if (currentRow == 0 || currentRow == numRows - 1) {
      goingDown = !goingDown;
    }

    currentRow += goingDown ? 1 : -1;
  }

  return rows.join("");
};

/**
 * Solution 2
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 *
 * @param {string} s
 * @param {number} numRows
 * @return {string}
 */
var solution2 = function (s, numRows) {
  const sLen = s.length;

  if (numRows == 1 || numRows > sLen) {
    return s;
  }

  const cycleLen = numRows * 2 - 2;
  let result = "";
  for (let row = 0; row < numRows; row++) {
    for (let cycle = row; cycle < sLen; cycle += cycleLen) {
      result += s[cycle];

      if (row > 0 && row < numRows - 1) {
        const diag_idx = cycle + cycleLen - row * 2;
        if (diag_idx < sLen) {
          result += s[diag_idx];
        }
      }
    }
  }

  return result;
};
