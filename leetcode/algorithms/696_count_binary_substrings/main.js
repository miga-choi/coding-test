/**
 * @param {string} s
 * @return {number}
 */
var countBinarySubstrings = function (s) {
  let count = 1;
  let prevCount = 0;
  let result = 0;

  for (let i = 1; i < s.length; i++) {
    if (s[i] == s[i - 1]) {
      count++;
    } else {
      result += Math.min(count, prevCount);
      prevCount = count;
      count = 1;
    }
  }

  return result + Math.min(count, prevCount);
};


// Solution
var solution = function (s) {
  let curr = 1, prev = 0, ans = 0;

  for (let i = 1; i < s.length; i++) {
    if (s[i] === s[i - 1]) {
      curr++;
    } else {
      (ans += Math.min(curr, prev)), (prev = curr), (curr = 1);
    }
  }

  return ans + Math.min(curr, prev);
};
