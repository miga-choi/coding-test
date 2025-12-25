/**
 * LIFO (Last-In, First-Out): Stack
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 *
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];

  for (const c of s) {
    switch (c) {
      case "(":
        stack.push(")");
        break;
      case "[":
        stack.push("]");
        break;
      case "{":
        stack.push("}");
        break;
      default:
        if (stack.length === 0 || stack.pop() !== c) {
          return false;
        }
        break;
    }
  }

  return stack.length === 0;
};


// Solution
/**
 * Stack + Hash Map
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 *
 * @param {string} s
 * @return {boolean}
 */
var solution = function (s) {
  if (s.length % 2 !== 0) {
    return false;
  }

  const stack = [];
  const map = {
    ")": "(",
    "}": "{",
    "]": "[",
  };

  for (let i = 0; i < s.length; i++) {
    const char = s[i];

    if (map[char]) {
      const topElement = stack.pop();

      if (topElement !== map[char]) {
        return false;
      }
    } else {
      stack.push(char);
    }
  }

  return stack.length === 0;
};
