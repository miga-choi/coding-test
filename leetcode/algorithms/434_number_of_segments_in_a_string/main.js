/**
 * @param {string} s
 * @return {number}
 */
var countSegments = function (s) {
  return s
    .split(" ")
    .map((v) => v.trim())
    .filter((v) => v).length;
};


// Solution
var solution = function (s) {
  return s.split(" ").filter((x) => x !== "").length;
};
