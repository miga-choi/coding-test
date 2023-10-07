/**
 * @param {number[]} g
 * @param {number[]} s
 * @return {number}
 */
var findContentChildren = function (g, s) {
  g.sort((p, n) => p - n);
  s.sort((p, n) => p - n);
  let gi = 0;
  for (let si = 0; si < s.length; si++) {
    if (s[si] >= g[gi]) {
      gi++;
    }
  }
  return gi;
};


// Best Solution
var bestSolution = function (g, s) {
  g.sort((a, b) => a - b);
  s.sort((a, b) => a - b);
  let j = 0,
    res = 0;
  for (let num of s) {
    if (num >= g[j]) res++, j++;
  }
  return res;
};
