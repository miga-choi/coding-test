/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isSubsequence = function (s, t) {
  while (s.length > 0) {
    const index = t.indexOf(s[0]);
    if (index === -1) {
      return false;
    }
    t = t.slice(index + 1, t.length);
    s = s.slice(1, s.length);
  }
  return true;
};


// Best Solution
var bestSolution = function (s, t) {
  //! Edge case
  //! if len of s is greater than len of t,
  //  return false because s cant be a subsequence of t
  if (s.length > t.length) return false;
  `
    Example:
      s='Leetcode'
      t='Code'
      here we are trying to find if 'Leetcode' is a subsequence of 'Code' 
      which is not possible because 'Leetcode' is longer than 'Code'
  `;
  const t_length = t.length;
  let subsequence = 0;
  for (let i = 0; i < t_length; i++) {
    if (s[subsequence] === t[i]) {
      // ! if it is matching, increment subsequence
      subsequence++;
    }
  }
  return subsequence === s.length;
};
