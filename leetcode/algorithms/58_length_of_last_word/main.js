/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLastWord = function (s) {
  const sArray = s.split(" ").filter((s_) => s_.trim());
  return sArray[sArray.length - 1].length;
};


// Solution
// Solution 1
var solution1 = function (s) {
  return s.trim().split(" ").pop().length;
};

// Solution 2
var solution2 = function (s) {
  let trimmedString = s.trim();
  return trimmedString.length - trimmedString.lastIndexOf(" ") - 1;
};
