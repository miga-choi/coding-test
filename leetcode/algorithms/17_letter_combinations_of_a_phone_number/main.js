/**
 * Recursion: Backtracking (DFS)
 * - Time Complexity: O(4ᴺ)
 * - Space Complexity: O(N)
 */
const lettersMap = {
  2: "abc",
  3: "def",
  4: "ghi",
  5: "jkl",
  6: "mno",
  7: "pqrs",
  8: "tuv",
  9: "wxyz",
};

/**
 * @param {string} digits
 * @param {{array: string[], row: string}} result
 * @param {number} index
 */
const backtracking = function (digits, result, index) {
  if (index === digits.length) {
    result.array.push(result.row);
    return;
  }

  for (const letter of lettersMap[digits[index]]) {
    result.row += letter;
    backtracking(digits, result, index + 1);
    result.row = result.row.slice(0, -1);
  }
};

/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  const result = {
    array: [],
    row: "",
  };

  backtracking(digits, result, 0);

  return result.array;
};


// Solution
/**
 * Recursion: Backtracking (DFS)
 * - Time Complexity: O(4ᴺ)
 * - Space Complexity: O(N)
 */
/**
 * @param {string} digits
 * @return {string[]}
 */
var solution = function (digits) {
  if (digits.length === 0) {
    return [];
  }

  const map = {
    2: "abc",
    3: "def",
    4: "ghi",
    5: "jkl",
    6: "mno",
    7: "pqrs",
    8: "tuv",
    9: "wxyz",
  };

  const result = [];

  /**
   * @param {number}
   * @param {string}
   */
  function backtrack(index, currentString) {
    if (index === digits.length) {
      result.push(currentString);
      return;
    }

    const currentDigit = digits[index];
    const letters = map[currentDigit];

    for (let i = 0; i < letters.length; i++) {
      const letter = letters[i];
      backtrack(index + 1, currentString + letter);
    }
  }

  backtrack(0, "");

  return result;
};
