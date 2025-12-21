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
 * Recursion: Backtracking (DFS)
 *
 * Complexities:
 *   - Time Complexity: O(4ᴺ)
 *   - Space Complexity: O(N)
 */
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
 *
 * Complexities:
 *   - Time Complexity: O(4ᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} digits
 * @return {string[]}
 */
var letterCombinations = function (digits) {
  const phoneMap = {
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
   * @param {number} index
   * @param {string} currentStr
   */
  function backtrack(index, currentStr) {
    if (index === digits.length) {
      result.push(currentStr);
      return;
    }

    const digit = digits[index];
    const letters = phoneMap[digit];

    for (const char of letters) {
      backtrack(index + 1, currentStr + char);
    }
  }

  backtrack(0, "");

  return result;
};
