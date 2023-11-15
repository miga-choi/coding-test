/**
 * @param {string} a
 * @param {string} b
 * @return {number}
 */
var findLUSlength = function (a, b) {
  if (a === b) {
    return -1;
  } else {
    return Math.max(a.length, b.length);
  }
};

// Best Solution
var bestSolution = function (a, b) {
  return a === b ? -1 : Math.max(a.length, b.length);
};
