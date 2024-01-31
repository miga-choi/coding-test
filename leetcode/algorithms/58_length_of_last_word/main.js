/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  const sArray = s.split(" ").filter((s_) => s_.trim());
  return sArray[sArray.length - 1].length;
};


// Best Solution
// Best Solution 1:
var bestSolution1 = function (s) {
  return s.trim().split(" ").pop().length;
};

// Best Solution 2:
var bestSolution2 = function (s) {
  let trimmedString = s.trim();
  return trimmedString.length - trimmedString.lastIndexOf(" ") - 1;
};
