/**
 * Brute-Force
 * - Time Complexity: O(N * M)
 * - Space Complexity: O(1)
 *
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
  const haystackLen = haystack.length;
  const needleLen = needle.length;

  if (needleLen > haystackLen) {
    return -1;
  }

  for (let haystackIdx = 0; haystackIdx <= haystack.length - needleLen; haystackIdx++) {
    let isMatch = true;

    for (let needleIdx = 0; needleIdx < needle.length; needleIdx++) {
      if (haystack[haystackIdx + needleIdx] != needle[needleIdx]) {
        isMatch = false;
        break;
      }
    }

    if (isMatch) {
      return haystackIdx;
    }
  }

  return -1;
};


// Solution
/**
 * Solution 1
 *
 * String.prototype.indexOf()
 * - Time Complexity: O(N * M)
 * - Space Complexity: O(1)
 *
 * @param {*} haystack
 * @param {*} needle
 * @returns
 */
var solution1 = function (haystack, needle) {
  return haystack.indexOf(needle);
};

/**
 * Solution 2
 *
 * Knuth-Morris-Pratt (KMP)
 * - Time Complexity: O(N + M)
 * - Space Complexity: O(M)
 *
 * @param {*} haystack
 * @param {*} needle
 * @returns
 */
var solution2 = function (haystack, needle) {
  if (needle.length === 0) {
    return 0;
  }

  const needleLen = needle.length;
  const haystackLen = haystack.length;

  const lps = new Array(needleLen).fill(0);
  let length = 0;
  let i = 1;
  while (i < needleLen) {
    if (needle[i] === needle[length]) {
      length++;
      lps[i] = length;
      i++;
    } else {
      if (length !== 0) {
        length = lps[length - 1];
      } else {
        lps[i] = 0;
        i++;
      }
    }
  }

  let hay_idx = 0;
  let nee_idx = 0;

  while (hay_idx < haystackLen) {
    if (haystack[hay_idx] === needle[nee_idx]) {
      hay_idx++;
      nee_idx++;
    }

    if (nee_idx === needleLen) {
      return hay_idx - nee_idx;
    } else if (hay_idx < haystackLen && haystack[hay_idx] !== needle[nee_idx]) {
      if (nee_idx !== 0) {
        nee_idx = lps[nee_idx - 1];
      } else {
        hay_idx++;
      }
    }
  }

  return -1;
};
