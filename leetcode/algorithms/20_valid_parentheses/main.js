/**
 * LIFO (Last-In, First-Out): Stack
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
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
 * LIFO (Last-In, First-Out): Stack
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {string} s
 * @return {boolean}
 */
var solution = function (s) {
  const stack = [];
  const map = {
    ")": "(",
    "}": "{",
    "]": "[",
  };

  for (let i = 0; i < s.length; i++) {
    const char = s[i];

    if (char === "(" || char === "{" || char === "[") {
      stack.push(char);
    } else if (char === ")" || char === "}" || char === "]") {
      if (stack.length === 0) {
        return false;
      }

      const lastOpen = stack.pop();
      if (lastOpen !== map[char]) {
        return false;
      }
    }
  }

  return stack.length === 0;
};
