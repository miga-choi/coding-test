/**
 * @param {number[][]} img
 * @return {number[][]}
 */
var imageSmoother = function (img) {
  const result = [];
  for (let i = 0; i < img.length; i++) {
    const row = [];
    for (let j = 0; j < img[i].length; j++) {
      let sum = 0;
      let count = 0;
      for (let k = -1; k < 2; k++) {
        for (let l = -1; l < 2; l++) {
          const m = i + k;
          const n = j + l;
          if (m < 0 || m >= img.length || n < 0 || n >= img[i].length) {
            continue;
          }
          sum += img[m][n];
          count++;
        }
      }
      row.push(Math.floor(sum / count));
    }
    result.push(row);
  }
  return result;
};

// Solution
const smoothen = function (img, x, y) {
  const m = img.length;
  const n = img[0].length;
  let sum = 0;
  let count = 0;

  for (let i = -1; i <= 1; ++i) {
    for (let j = -1; j <= 1; ++j) {
      const nx = x + i;
      const ny = y + j;
      if (nx >= 0 && nx < m && ny >= 0 && ny < n) {
        sum += img[nx][ny];
        ++count;
      }
    }
  }

  return Math.floor(sum / count);
};

var solution = function (img) {
  const m = img.length;
  const n = img[0].length;
  const res = new Array(m).fill(0).map(() => new Array(n).fill(0));

  for (let i = 0; i < m; ++i) {
    for (let j = 0; j < n; ++j) {
      res[i][j] = smoothen(img, i, j);
    }
  }

  return res;
};
