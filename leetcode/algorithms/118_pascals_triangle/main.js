/**
 * DP
 * 
 * Complexities:
 *   N - `numRows`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N²)
 */
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var generate = function (numRows) {
  const result = [];
  for (let i = 0; i < numRows; i++) {
    const row = [];
    for (let j = 0; j <= i; j++) {
      if (j === 0 || j === i) {
        row.push(1);
      } else {
        row.push(result[i - 1][j - 1] + result[i - 1][j]);
      }
    }
    result.push(row);
  }
  return result;
};


// Solution
/**
 * DP
 * 
 * Complexities:
 *   N - `numRows`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N²)
 */
/**
 * @param {number} numRows
 * @return {number[][]}
 */
var solution = function (numRows) {
  if (numRows === 0) {
    return [];
  }

  const triangle = [[1]];

  for (let i = 1; i < numRows; i++) {
    const prevRow = triangle[i - 1];

    const currentRow = new Array(i + 1).fill(1);

    for (let j = 1; j < i; j++) {
      currentRow[j] = prevRow[j - 1] + prevRow[j];
    }

    triangle.push(currentRow);
  }

  return triangle;
};
