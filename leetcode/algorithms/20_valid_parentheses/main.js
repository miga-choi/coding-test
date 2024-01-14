/**
 * @param {string} s
 * @return {boolean}
 */
var isValid = function (s) {
  const stack = [];

  for (const c of s) {
    if (c === "(") {
      stack.push(")");
    } else if (c === "[") {
      stack.push("]");
    } else if (c === "{") {
      stack.push("}");
    } else {
      if (stack.pop() !== c) {
        return false;
      }
    }
  }

  return stack.length <= 0;
};


// Best Solution
var bestSolution = function (s) {
  // Initialize stack to store the closing brackets expected...
  let stack = [];
  // Traverse each charater in input string...
  for (let idx = 0; idx < s.length; idx++) {
    // If open parentheses are present, push it to stack...
    if (s[idx] === "{") {
      stack.push("}");
    } else if (s[idx] === "[") {
      stack.push("]");
    } else if (s[idx] === "(") {
      stack.push(")");
    }
    // If a close bracket is found, check that it matches the last stored open bracket
    else if (stack.pop() !== s[idx]) {
      return false;
    }
  }
  return !stack.length;
};
