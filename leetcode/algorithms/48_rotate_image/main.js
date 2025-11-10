/**
 * Reverse & Transpose
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
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
 * Solution 1
 *
 * Transpose & Reverse
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var solution1 = function (matrix) {
  const n = matrix.length;

  for (let i = 0; i < n; i++) {
    for (let j = i; j < n; j++) {
      const temp = matrix[i][j];
      matrix[i][j] = matrix[j][i];
      matrix[j][i] = temp;
    }
  }

  for (let i = 0; i < n; i++) {
    matrix[i].reverse();
  }
};

/**
 * Solution 2
 *
 * Rotate Groups of Four
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var solution2 = function (matrix) {
  const n = matrix.length;

  for (let i = 0; i < Math.floor(n / 2); i++) {
    for (let j = i; j < n - 1 - i; j++) {
      const temp = matrix[i][j];

      matrix[i][j] = matrix[n - 1 - j][i];

      matrix[n - 1 - j][i] = matrix[n - 1 - i][n - 1 - j];

      matrix[n - 1 - i][n - 1 - j] = matrix[j][n - 1 - i];

      matrix[j][n - 1 - i] = temp;
    }
  }
};
