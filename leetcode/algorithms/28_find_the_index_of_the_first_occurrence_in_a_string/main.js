/**
 * Brute Force, Sliding Window
 *
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(1)
 */
/**
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
 * Brute Force, Sliding Window
 *
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(1)
 */
/**
 * @param {*} haystack
 * @param {*} needle
 * @returns
 */
var solution1 = function (haystack, needle) {
  const N = haystack.length;
  const M = needle.length;

  for (let i = 0; i <= N - M; i++) {
    let j = 0;

    while (j < M) {
      if (haystack[i + j] !== needle[j]) {
        break;
      }
      j++;
    }

    if (j === M) {
      return i;
    }
  }

  return -1;
};

/**
 * Solution 2
 *
 * KMP (Knuth-Morris-Pratt)
 *
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(M)
 */
/**
 * @param {*} haystack
 * @param {*} needle
 * @returns
 */
var solution2 = function (haystack, needle) {
  const N = haystack.length;
  const M = needle.length;

  const lps = new Array(M).fill(0);
  let prevLPS = 0;
  let i = 1;

  while (i < M) {
    if (needle[i] === needle[prevLPS]) {
      prevLPS++;
      lps[i] = prevLPS;
      i++;
    } else {
      if (prevLPS === 0) {
        lps[i] = 0;
        i++;
      } else {
        prevLPS = lps[prevLPS - 1];
      }
    }
  }

  let hIdx = 0;
  let nIdx = 0;

  while (hIdx < N) {
    if (haystack[hIdx] === needle[nIdx]) {
      hIdx++;
      nIdx++;
      if (nIdx === M) {
        return hIdx - M;
      }
    } else {
      if (nIdx === 0) {
        hIdx++;
      } else {
        nIdx = lps[nIdx - 1];
      }
    }
  }

  return -1;
};

/**
 * Solution 3
 *
 * built-in: indexOf()
 *
 * Complexities:
 *   N - Length of `haystack`
 *   M - Length of `needle`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(M)
 */
/**
 * @param {*} haystack
 * @param {*} needle
 * @returns
 */
var solution3 = function (haystack, needle) {
  return haystack.indexOf(needle);
};
