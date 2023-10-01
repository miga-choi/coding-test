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


// Best Solution
var bestSolution = function (s) {
  return s.split(" ").filter((x) => x !== "").length;
};
