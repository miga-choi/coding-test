/**
 * Two-Pointer
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  s = s.toLowerCase().replace(/[^a-z0-9]/gi, "");
  i = 0;

  while (i < s.length - 1 - i) {
    if (s[i] !== s[s.length - 1 - i]) {
      return false;
    }
    i++;
  }

  return true;
};


// Solution
/**
 * Solution 1
 *
 * Compare strings
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {string} s
 * @return {boolean}
 */
var solution1 = function (s) {
  const cleaned = s.toLowerCase().replace(/[^a-z0-9]/g, "");

  const reversed = cleaned.split("").reverse().join("");

  return cleaned === reversed;
};

/**
 * Solution 2
 *
 * Two-Pointer
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {string} s
 * @return {boolean}
 */
var solution2 = function (s) {
  let left = 0;
  let right = s.length - 1;

  const alphanumeric = /^[a-z0-9]+$/i;

  while (left < right) {
    while (left < right && !alphanumeric.test(s[left])) {
      left++;
    }

    while (left < right && !alphanumeric.test(s[right])) {
      right--;
    }

    if (s[left].toLowerCase() !== s[right].toLowerCase()) {
      return false;
    }

    left++;
    right--;
  }

  return true;
};
