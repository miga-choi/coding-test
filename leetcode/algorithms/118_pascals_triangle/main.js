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
// Solution 1: Recursion
var solution1 = function (numRows) {
  if (numRows === 0) {
    return [];
  }
  if (numRows === 1) {
    return [[1]];
  }

  let prevRows = solution1(numRows - 1);
  let newRow = new Array(numRows).fill(1);

  for (let i = 1; i < numRows - 1; i++) {
    newRow[i] = prevRows[numRows - 2][i - 1] + prevRows[numRows - 2][i];
  }

  prevRows.push(newRow);
  return prevRows;
};

// Solution 2: Combinatorial Formula
var solution2 = function (numRows) {
  let result = [];
  if (numRows === 0) {
    return result;
  }

  let firstRow = [1];
  result.push(firstRow);

  for (let i = 1; i < numRows; i++) {
    let prevRow = result[i - 1];
    let currentRow = [1];

    for (let j = 1; j < i; j++) {
      currentRow.push(prevRow[j - 1] + prevRow[j]);
    }

    currentRow.push(1);
    result.push(currentRow);
  }

  return result;
};

// Solution 3: Dynamic Programming with 1D Array
var solution3 = function (numRows) {
  if (numRows === 0) {
    return [];
  }
  if (numRows === 1) {
    return [[1]];
  }

  let prevRows = generate(numRows - 1);
  let prevRow = prevRows[prevRows.length - 1];
  let currentRow = [1];

  for (let i = 1; i < numRows - 1; i++) {
    currentRow.push(prevRow[i - 1] + prevRow[i]);
  }

  currentRow.push(1);
  prevRows.push(currentRow);

  return prevRows;
};
