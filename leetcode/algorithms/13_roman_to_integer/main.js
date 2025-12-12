/**
 * Map
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var romanToInt = function (s) {
  let result = 0;
  const romanMap = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  s = s.replaceAll("CM", "DCCCC");
  s = s.replaceAll("CD", "CCCC");
  s = s.replaceAll("XC", "LXXXX");
  s = s.replaceAll("XL", "XXXX");
  s = s.replaceAll("IX", "VIIII");
  s = s.replaceAll("IV", "IIII");

  for (const c of s) {
    result += romanMap[c];
  }

  return result;
};


// Solution
/**
 * Map
 *
 * Complexities:
 *   N - Length of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {number}
 */
var solution = function (s) {
  const romanMap = {
    I: 1,
    V: 5,
    X: 10,
    L: 50,
    C: 100,
    D: 500,
    M: 1000,
  };

  let total = 0;

  for (let i = 0; i < s.length; i++) {
    const currentVal = romanMap[s[i]];
    const nextVal = romanMap[s[i + 1]];

    if (nextVal > currentVal) {
      total -= currentVal;
    } else {
      total += currentVal;
    }
  }

  return total;
};
