/**
 * Builtin function
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  const sArray = s.split(" ").filter((s_) => s_.trim());
  return sArray[sArray.length - 1].length;
};


// Solution
/**
 * Solution 1
 *
 * Reverse Traversal
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
var solution1 = function (s) {
  let length = 0;
  let i = s.length - 1;

  while (i >= 0 && s[i] === " ") {
    i--;
  }

  while (i >= 0 && s[i] !== " ") {
    length++;
    i--;
  }

  return length;
};

/**
 * Solution 2
 *
 * Built-in function
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
var solution2 = function (s) {
  const words = s.trim().split(" ");
  return words[words.length - 1].length;
};
