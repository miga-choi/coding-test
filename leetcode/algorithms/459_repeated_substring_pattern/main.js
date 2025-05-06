/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function (s) {
  return s.slice(1, s.length).concat(s.slice(0, s.length - 1)).indexOf(s) >= 0;
};


// Solution
var solution = function (s) {
  let size = s.length;
  let sFold = s.substr(1, size) + s.substr(0, size - 1);
  return sFold.indexOf(s) != -1;
};
