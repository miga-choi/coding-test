/**
 * Cleanup + Reverse Chunking
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var licenseKeyFormatting = function (s, k) {
  s = s.replaceAll("-", "");
  result = "";

  for (let i = s.length; i >= 0; i -= k) {
    if (i > k) {
      result = "-" + s.substring(i - k, i) + result;
    } else {
      result = s.substring(i - k, i) + result;
    }
  }

  return result.toUpperCase();
};


// Solution
/**
 * Solution 1
 *
 * Reverse Iteration (Build from the End)
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var solution1 = function (s, k) {
  const result = [];
  let count = 0;

  for (let i = s.length - 1; i >= 0; i--) {
    const c = s[i];
    if (c === "-") {
      continue;
    }

    if (count === k) {
      result.push("-");
      count = 0;
    }

    result.push(c.toUpperCase());
    count++;
  }

  return result.reverse().join("");
};

/**
 * Solution 2
 *
 * Cleanup + First Group Offset
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var solution2 = function (s, k) {
  const clean = s.replaceAll("-", "").toUpperCase();
  if (clean.length === 0) {
    return "";
  }

  const first = clean.length % k || k;
  const groups = [clean.slice(0, first)];

  for (let i = first; i < clean.length; i += k) {
    groups.push(clean.slice(i, i + k));
  }

  return groups.join("-");
};

/**
 * Solution 3
 *
 * Regular Expression (Lookahead Grouping)
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var solution3 = function (s, k) {
  const clean = s.replaceAll("-", "").toUpperCase();
  const pattern = new RegExp(`\\B(?=(?:[A-Z0-9]{${k}})+$)`, "g");
  return clean.replace(pattern, "-");
};
