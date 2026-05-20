/**
 * Complexities:
 *   N - `columnNumber`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function (columnNumber) {
  const alphabet = [
    "A",
    "B",
    "C",
    "D",
    "E",
    "F",
    "G",
    "H",
    "I",
    "J",
    "K",
    "L",
    "M",
    "N",
    "O",
    "P",
    "Q",
    "R",
    "S",
    "T",
    "U",
    "V",
    "W",
    "X",
    "Y",
    "Z",
  ];

  let result = "";

  while (columnNumber > 0) {
    result = alphabet[(columnNumber - 1) % 26] + result;
    columnNumber = Math.floor((columnNumber - 1) / 26);
  }

  return result;
};


// Solution
/**
 * Complexities:
 *   N - `columnNumber`
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number} columnNumber
 * @return {string}
 */
var solution = function (n) {
  const result = [];

  while (columnNumber > 0) {
    columnNumber--;

    const remainder = columnNumber % 26;

    const char = String.fromCharCode(remainder + 65);
    result.push(char);

    columnNumber = Math.floor(columnNumber / 26);
  }

  return result.reverse().join("");
};
