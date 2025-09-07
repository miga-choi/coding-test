/**
 * Frequency Counter
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {string} s
 * @return {number}
 */
var firstUniqChar = function (s) {
  const alphabetNumArray = new Array(26).fill(0);

  for (const c of s) {
    alphabetNumArray[c.charCodeAt(0) - 97]++;
  }

  for (let i = 0; i < s.length; i++) {
    if (alphabetNumArray[s.charCodeAt(i) - 97] === 1) {
      return i;
    }
  }

  return -1;
};


// Solution
/**
 * Solution 1
 *
 * Hash Table
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {string} s
 * @return {number}
 */
var solution1 = function (s) {
  const frequencyMap = new Map();

  for (const char of s) {
    frequencyMap.set(char, (frequencyMap.get(char) || 0) + 1);
  }

  for (let i = 0; i < s.length; i++) {
    const char = s[i];
    if (frequencyMap.get(char) === 1) {
      return i;
    }
  }

  return -1;
};

/**
 * Solution 2
 *
 * Built-in functions
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 *
 * @param {string} s
 * @return {number}
 */
var solution2 = function (s) {
  for (let i = 0; i < s.length; i++) {
    const char = s[i];
    if (s.indexOf(char) === s.lastIndexOf(char)) {
      return i;
    }
  }

  return -1;
};

/**
 * Solution 3
 *
 * Frequency Counting
 * - Time Complexity: O(N)
 * - Space Complexity: O(1)
 *
 * @param {string} s
 * @return {number}
 */
var solution3 = function (s) {
  const charCounts = new Array(26).fill(0);
  const charCodeOfA = "a".charCodeAt(0);

  for (let i = 0; i < s.length; i++) {
    const charIndex = s.charCodeAt(i) - charCodeOfA;
    charCounts[charIndex]++;
  }

  for (let i = 0; i < s.length; i++) {
    const charIndex = s.charCodeAt(i) - charCodeOfA;
    if (charCounts[charIndex] === 1) {
      return i;
    }
  }

  return -1;
};
