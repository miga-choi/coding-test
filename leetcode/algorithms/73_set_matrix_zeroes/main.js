/**
 * Marking First Row and Column as Flag
 *
 * Complexities:
 *   M - Length of `matrix`
 *   N - Length of `matrix[0]`
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var setZeroes = function (matrix) {
  const m = matrix.length;
  const n = matrix[0].length;
  let isFirstColZero = false;

  for (let i = 0; i < m; i++) {
    if (matrix[i][0] === 0) {
      isFirstColZero = true;
    }

    for (let j = 1; j < n; j++) {
      if (matrix[i][j] === 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (let i = m - 1; i >= 0; i--) {
    for (let j = n - 1; j >= 1; j--) {
      if (matrix[i][0] === 0 || matrix[0][j] === 0) {
        matrix[i][j] = 0;
      }
    }

    if (isFirstColZero) {
      matrix[i][0] = 0;
    }
  }
};


// Solution
/**
 * Marking First Row and Column as Flag
 *
 * Complexities:
 *   M - Length of `matrix`
 *   N - Length of `matrix[0]`
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[][]} matrix
 * @return {void} Do not return anything, modify matrix in-place instead.
 */
var solution = function (matrix) {
  const m = matrix.length;
  const n = matrix[0].length;

  let isFirstRowZero = false;
  let isFirstColZero = false;

  for (let i = 0; i < m; i++) {
    if (matrix[i][0] === 0) {
      isFirstColZero = true;
      break;
    }
  }

  for (let j = 0; j < n; j++) {
    if (matrix[0][j] === 0) {
      isFirstRowZero = true;
      break;
    }
  }

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      if (matrix[i][j] === 0) {
        matrix[i][0] = 0;
        matrix[0][j] = 0;
      }
    }
  }

  for (let i = 1; i < m; i++) {
    for (let j = 1; j < n; j++) {
      if (matrix[i][0] === 0 || matrix[0][j] === 0) {
        matrix[i][j] = 0;
      }
    }
  }

  if (isFirstColZero) {
    for (let i = 0; i < m; i++) {
      matrix[i][0] = 0;
    }
  }

  if (isFirstRowZero) {
    for (let j = 0; j < n; j++) {
      matrix[0][j] = 0;
    }
  }
};
