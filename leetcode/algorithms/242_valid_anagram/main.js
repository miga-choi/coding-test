/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isAnagram = function (s, t) {
  let sMap = {};

  for (const c_ of s) {
    if (sMap[c_]) {
      sMap[c_] = sMap[c_] + 1;
    } else {
      sMap[c_] = 1;
    }
  }

  for (const c_ of t) {
    if (sMap[c_] > 0) {
      sMap[c_] = sMap[c_] - 1;
    } else {
      return false;
    }
  }

  for (const c_ in sMap) {
    if (sMap[c_] > 0) {
      return false;
    }
  }

  return true;
};


// Solution
var solution = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  var freq = new Array(26).fill(0);
  for (var i = 0; i < s.length; i++) {
    freq[s.charCodeAt(i) - "a".charCodeAt(0)]++;
    freq[t.charCodeAt(i) - "a".charCodeAt(0)]--;
  }

  for (var i = 0; i < freq.length; i++) {
    if (freq[i] !== 0) {
      return false;
    }
  }

  return true;
};
