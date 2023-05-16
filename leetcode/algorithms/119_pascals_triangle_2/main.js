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

// Best Solution
var bestSolution = function (r) {
  var ans = new Array(r + 1);
  ans[0] = ans[r] = 1;
  for (i = 1, up = r; i < r; i++, up--) {
    ans[i] = (ans[i - 1] * up) / i;
  }
  return ans;
};
