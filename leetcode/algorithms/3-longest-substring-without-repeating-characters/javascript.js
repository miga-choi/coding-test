/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  const map = {};
  var length = 0;

  return s.split('').reduce((maxLength, v, i) => {
    if (map[v] >= length) {
      length = map[v] + 1;
    }
    map[v] = i;
    if (maxLength >= i - length + 1) {
      return maxLength;
    } else {
      return i - length + 1;
    }
  }, 0);
};
