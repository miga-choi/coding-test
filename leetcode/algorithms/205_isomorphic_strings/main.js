/**
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {string} t
 * @return {boolean}
 */
var isIsomorphic = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  const sMap = {};
  const tMap = {};

  for (let i = 0; i < s.length; i++) {
    if (sMap[s[i]] !== tMap[t[i]]) {
      return false;
    }
    sMap[s[i]] = i;
    tMap[t[i]] = i;
  }

  return true;
};


// Solution
/**
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
var solution = function (s, t) {
  if (s.length !== t.length) {
    return false;
  }

  const mapS = new Map();
  const mapT = new Map();

  for (let i = 0; i < s.length; i++) {
    const charS = s[i];
    const charT = t[i];

    if (mapS.has(charS)) {
      if (mapS.get(charS) !== charT) {
        return false;
      }
    } else {
      mapS.set(charS, charT);
    }

    if (mapT.has(charT)) {
      if (mapT.get(charT) !== charS) {
        return false;
      }
    } else {
      mapT.set(charT, charS);
    }
  }

  return true;
};
