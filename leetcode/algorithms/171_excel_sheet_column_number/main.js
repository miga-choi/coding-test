/**
 * Complexities:
 *   N - Size of `columnTitle`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
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
/**
 * Complexities:
 *   N - Size of `columnTitle`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} columnTitle
 * @return {number}
 */
var solution = function (s) {
  let result = 0;

  for (let i = 0; i < columnTitle.length; i++) {
    const charValue = columnTitle.charCodeAt(i) - 64;

    result = result * 26 + charValue;
  }

  return result;
};
