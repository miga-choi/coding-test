/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function (pattern, s) {
  const sArray = s.split(" ");

  if (sArray.length !== pattern.length) {
    return false;
  }

  const patternMap = new Map();

  for (let i = 0; i < sArray.length; i++) {
    if (patternMap.get(pattern[i])) {
      if (patternMap.get(pattern[i]) !== sArray[i]) {
        return false;
      }
    } else {
      for (const [key, value] of patternMap.entries()) {
        if (value === sArray[i]) {
          return false;
        }
      }
      patternMap.set(pattern[i], sArray[i]);
    }
  }

  return true;
};


// Solution
var solution = function (pattern, str) {
  const words = str.split(/\s+/);
  const map = new Map();

  if (words.length !== pattern.length) {
    return false;
  }

  if (new Set(words).size !== new Set(pattern).size) {
    return false;
  }

  for (let i = 0; i < pattern.length; i++) {
    if (map.has(pattern[i]) && map.get(pattern[i]) !== words[i]) {
      return false;
    }
    map.set(pattern[i], words[i]);
  }

  return true;
};
