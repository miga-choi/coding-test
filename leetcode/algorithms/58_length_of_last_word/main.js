/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  const sArray = s.split(' ').filter((s_) => s_.trim());
  return sArray[sArray.length - 1].length;
};

// Best Solution
var bestSolution = function (s) {
  return s.trim().split(' ').pop().length;
};
