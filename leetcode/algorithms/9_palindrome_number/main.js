/**
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  const s = x.toString();
  const length = s.length;

  if (length === 1) {
    return true;
  }
  if (s.startsWith("-") || s.startsWith("0") || s.endsWith("0")) {
    return false;
  }
  if (length % 2 === 0) {
    return checkPalindrome(length / 2 - 1, length / 2);
  } else {
    return checkPalindrome(parseInt(length / 2) - 1, parseInt(length / 2) + 1);
  }

  function checkPalindrome(i1, i2) {
    let ifPalindrome = true;
    while (i1 >= 0 && i2 < length) {
      if (s[i1] !== s[i2]) {
        ifPalindrome = false;
      }
      i1--;
      i2++;
    }
    return ifPalindrome;
  }
};


// Solution
/**
 * Solution 1
 * 
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(logᴺ)
 */
/**
 * @param {number} x
 * @return {boolean}
 */
var solution1 = function (x) {
  if (x < 0) {
    return false;
  }

  const str = x.toString();
  const reversedStr = str.split("").reverse().join("");

  return str === reversedStr;
};

/**
 * Solution 2
 * 
 * Complexities:
 *   - Time Complexity: O(logᴺ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} x
 * @return {boolean}
 */
var solution2 = function (x) {
  if (x < 0 || (x % 10 === 0 && x !== 0)) {
    return false;
  }

  let reversedHalf = 0;

  while (x > reversedHalf) {
    reversedHalf = reversedHalf * 10 + (x % 10);
    x = Math.floor(x / 10);
  }

  return x === reversedHalf || x === Math.floor(reversedHalf / 10);
};
