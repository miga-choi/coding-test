/**
 * @param {number[][]} mat
 * @param {number} r
 * @param {number} c
 * @return {number[][]}
 */
var matrixReshape = function (mat, r, c) {
  const nums = [];
  for (let i = 0; i < mat.length; i++) {
    for (let j = 0; j < mat[i].length; j++) {
      nums.push(mat[i][j]);
    }
  }

  if (nums.length !== r * c) {
    return mat;
  }

  const result = new Array();

  let count = 0;
  for (let row = 0; row < r; row++) {
    const newRow = [];
    for (let col = 0; col < c; col++) {
      newRow.push(nums[count]);
      count++;
    }
    result.push(newRow);
  }

  return result;
};


// Solution
var solution = function (mat, r, c) {
  var arr = mat.flat();
  if (r * c != arr.length) {
    return mat;
  }

  var res = [];
  while (arr.length) {
    res.push(arr.splice(0, c));
  }

  return res;
};
