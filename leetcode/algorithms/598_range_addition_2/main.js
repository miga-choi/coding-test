/**
 * @param {number} m
 * @param {number} n
 * @param {number[][]} ops
 * @return {number}
 */
var maxCount = function (m, n, ops) {
  let minM = m;
  let minN = n;

  for (let i = 0; i < ops.length; i++) {
    minM = Math.min(minM, ops[i][0]);
    minN = Math.min(minN, ops[i][1]);
  }

  return minM * minN;
};


// Solution
var solution = function (m, n, ops) {
  var min_row = m;
  var min_col = n;

  for (let i = 0; i < ops.length; i++) {
    if (ops[i][0] < min_row) {
      min_row = ops[i][0];
    }
    if (ops[i][1] < min_col) {
      min_col = ops[i][1];
    }
  }

  return min_row * min_col;
};
