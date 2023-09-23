/**
 * @param {string} s
 * @return {number}
 */
var longestPalindrome = function (s) {
  let result = 0;
  const sMap = new Map();

  for (const c of s) {
    if (sMap.get(c)) {
      result += 2;
      sMap.delete(c);
    } else {
      sMap.set(c, 1);
    }
  }

  if (sMap.size > 0) {
    result++;
  }

  return result;
};


// Best Solution
var bestSolution = function (s) {
  let ans = 0;
  let keys = {};

  for (let char of s) {
    keys[char] = (keys[char] || 0) + 1;
    if (keys[char] % 2 == 0) ans += 2;
  }

  return s.length > ans ? ans + 1 : ans;
};
