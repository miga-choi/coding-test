/**
 * Transpose & Reverse
 *
 * Complexities:
 *   N - Length of `matrix`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var rotate = function (matrix) {
  const size = matrix.length;

  matrix.reverse();

  for (let row = 0; row < size; row++) {
    for (let col = row + 1; col < size; col++) {
      const temp = matrix[row][col];
      matrix[row][col] = matrix[col][row];
      matrix[col][row] = temp;
    }
  }
};


// Solution
/**
 * Transpose & Reverse
 *
 * Complexities:
 *   N - Length of `matrix`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var solution = function (matrix) {
  const n = matrix.length;

  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      [matrix[i][j], matrix[j][i]] = [matrix[j][i], matrix[i][j]];
    }
  }

  for (let i = 0; i < n; i++) {
    matrix[i].reverse();
  }
};
