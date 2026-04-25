/**
 * DP
 *
 * Complexities:
 *   N - `rowIndex`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var getRow = function (rowIndex) {
  const rows = [];

  for (let i = 0; i <= rowIndex; i++) {
    const row = [];
    for (let j = 0; j <= i; j++) {
      if (j === 0 || j === i) {
        row.push(1);
      } else {
        row.push(rows[i - 1][j - 1] + rows[i - 1][j]);
      }
    }
    rows.push(row);
  }

  return rows[rowIndex];
};


// Solution
/**
 * Solution 1
 *
 * DP
 *
 * Complexities:
 *   N - `rowIndex`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var solution1 = function (rowIndex) {
  const row = new Array(rowIndex + 1).fill(1);

  for (let i = 2; i <= rowIndex; i++) {
    for (let j = i - 1; j > 0; j--) {
      row[j] = row[j] + row[j - 1];
    }
  }

  return row;
};

/**
 * Solution 2
 *
 * Binomial Coefficient
 *
 * Complexities:
 *   N - `rowIndex`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number} rowIndex
 * @return {number[]}
 */
var solution2 = function (rowIndex) {
  const row = new Array(rowIndex + 1).fill(1);

  let prev = 1;

  for (let j = 1; j <= rowIndex; j++) {
    let current = (prev * (rowIndex - j + 1)) / j;

    row[j] = current;
    prev = current;
  }

  return row;
};
