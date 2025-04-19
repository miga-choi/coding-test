/**
 * @param {string} columnTitle
 * @return {number}
 */
var titleToNumber = function (columnTitle) {
  const alphabetMap = {
    A: 1,
    B: 2,
    C: 3,
    D: 4,
    E: 5,
    F: 6,
    G: 7,
    H: 8,
    I: 9,
    J: 10,
    K: 11,
    L: 12,
    M: 13,
    N: 14,
    O: 15,
    P: 16,
    Q: 17,
    R: 18,
    S: 19,
    T: 20,
    U: 21,
    V: 22,
    W: 23,
    X: 24,
    Y: 25,
    Z: 26,
  };
  let result = 0;

  for (let i = columnTitle.length - 1; i >= 0; i--) {
    result += 26 ** (columnTitle.length - 1 - i) * alphabetMap[columnTitle[i]];
  }

  return result;
};


// Solution
var solution = function (s) {
  const charCodeBase = "A".charCodeAt(0) - 1;
  const n = s.length;
  let number = 0;

  /*
   * Think of it as base 26. For example,
   * Column number of "AB" = 1 * 26^1 + 2 * 26^0
   */
  for (let i = 0; i < n; i++) {
    number += (s.charCodeAt(i) - charCodeBase) * Math.pow(26, n - i - 1);
  }

  return number;
};
