/**
 * Regex
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
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
 * Regex
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
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
 * Two-Pointers
 *
 * Complexities:
 *   N - Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var solution2 = function (s) {
  let left = 0;
  let right = s.length - 1;

  const isAlphanumeric = (char) => {
    const code = char.charCodeAt(0);
    return (
      (code >= 48 && code <= 57) ||
      (code >= 65 && code <= 90) ||
      (code >= 97 && code <= 122)
    );
  };

  while (left < right) {
    while (left < right && !isAlphanumeric(s[left])) {
      left++;
    }

    while (left < right && !isAlphanumeric(s[right])) {
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
