/**
 * @param {string[]} strs
 * @return {string}
 */
var longestCommonPrefix = function (strs) {
  const minStrLength = Math.min(...strs.map((v) => v.length));
  let result = "";

  for (let i = 0; i < minStrLength; i++) {
    const char = strs[0][i];
    if (strs.every((str) => str[i] === char)) {
      result += char;
    } else {
      break;
    }
  }

  return result;
};


// Best Solution
// Best Solution 1: reduce
var bestSolution = function (strs) {
  if (strs === undefined || strs.length === 0) {
    return "";
  }

  return strs.reduce((prev, next) => {
    let i = 0;
    while (prev[i] && next[i] && prev[i] === next[i]) {
      i++;
    }
    return prev.slice(0, i);
  });
};

// Best Solution 2:
var bestSolution = function (strs) {
  if (!strs.length) {
    return "";
  }
  let prefix = "";
  let maxPrefixLength = Math.min(...strs.map((str) => str.length));
  for (let i = 0; i < maxPrefixLength; i++) {
    let char = strs[0][i];
    if (strs.every((str) => str[i] === char)) {
      prefix += char;
    } else {
      break;
    }
  }
  return prefix;
};
