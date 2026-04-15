/**
 * Layer Peeling
 *
 * Complexities:
 *   M - matrixSize
 *   N - matrixColSize
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(M * N)
 */
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var spiralOrder = function (matrix) {
  if (matrix.length === 1) {
    return matrix[0];
  }

  const m = matrix.length;
  const n = matrix[0].length;

  const result = new Array();

  let top = 0, bottom = m - 1;
  let left = 0, right = n - 1;

  while (top <= bottom && left <= right) {
    // [top][left -> right]
    for (let col = left; col <= right; col++) {
      result.push(matrix[top][col]);
    }
    top++;

    // [top -> bottom][right]
    for (let row = top; row <= bottom; row++) {
      result.push(matrix[row][right]);
    }
    right--;

    // [bottom][right -> left]
    if (top <= bottom) {
      for (let col = right; col >= left; col--) {
        result.push(matrix[bottom][col]);
      }
      bottom--;
    }

    // [bottom -> top][left]
    if (left <= right) {
      for (let row = bottom; row >= top; row--) {
        result.push(matrix[row][left]);
      }
      left++;
    }
  }

  return result;
};


// Solution
/**
 * Layer Peeling
 *
 * Complexities:
 *   M - matrixSize
 *   N - matrixColSize
 *   - Time Complexity: O(M * N)
 *   - Space Complexity: O(M * N)
 */
/**
 * @param {number[][]} matrix
 * @return {number[]}
 */
var solution = function (matrix) {
  const result = [];
  let top = 0;
  let bottom = matrix.length - 1;
  let left = 0;
  let right = matrix[0].length - 1;

  while (left <= right && top <= bottom) {
    // left -> right
    for (let i = left; i <= right; i++) {
      result.push(matrix[top][i]);
    }
    top++;

    // top -> bottom
    for (let i = top; i <= bottom; i++) {
      result.push(matrix[i][right]);
    }
    right--;

    if (left <= right && top <= bottom) {
      // right -> left
      for (let i = right; i >= left; i--) {
        result.push(matrix[bottom][i]);
      }
      bottom--;

      // bottom -> top
      for (let i = bottom; i >= top; i--) {
        result.push(matrix[i][left]);
      }
      left++;
    }
  }

  return result;
};
