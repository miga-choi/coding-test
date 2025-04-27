/**
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
  const sMap = new Map();

  for (let i = 0; i < s.length; i++) {
    if (sMap.get(s[i]) != null) {
      sMap.set(s[i], -1);
    } else {
      sMap.set(s[i], i);
    }
  }

  let result = -1;

  for (const value of sMap.values()) {
    if (result === -1 || (value >= 0 && value < result)) {
      result = value;
    }
  }

  return result;
};


// Solution
var solution = function (s) {
  for (let idx = 0; idx < s.length; idx++) {
    // If same...
    if (s.indexOf(s[idx]) === s.lastIndexOf(s[idx])) {
      // return the index of that unique character
      return idx;
    }
  }

  // If no character appeared exactly once...
  return -1;
};
