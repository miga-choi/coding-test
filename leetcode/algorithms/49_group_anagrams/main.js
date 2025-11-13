/*
 * Complexities:
 *   N - size of strs
 *   K - max size of strings in strs
 *   - Time Complexity: O(N * K * logᴷ)
 *   - Space Complexity: O(N * K)
 */
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var groupAnagrams = function (strs) {
  const strMap = new Map();

  for (let i = 0; i < strs.length; i++) {
    const sortedStr = strs[i].split("").sort().join("");

    if (!strMap.has(sortedStr)) {
      strMap.set(sortedStr, new Array());
    }

    strMap.get(sortedStr).push(strs[i]);
  }

  return Array.from(strMap.values());
};


// Solution
/**
 * Solution 1
 *
 * Sort & Group
 *
 * Complexities:
 *   N - size of strs
 *   K - max size of strings in strs
 *   - Time Complexity: O(N * K * logᴷ)
 *   - Space Complexity: O(N * K)
 */
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var solution1 = function (strs) {
  const groups = {};

  for (const str of strs) {
    const key = str.split("").sort().join("");

    if (!groups[key]) {
      groups[key] = [];
    }

    groups[key].push(str);
  }

  return Object.values(groups);
};

/**
 * Solution 2
 *
 * Count & Group
 *
 * Complexities:
 *   N - size of strs
 *   K - max size of strings in strs
 *   - Time Complexity: O(N * K)
 *   - Space Complexity: O(N * K)
 */
/**
 * @param {string[]} strs
 * @return {string[][]}
 */
var solution2 = function (strs) {
  const groups = {};
  const charCodeOfA = "a".charCodeAt(0);

  for (const str of strs) {
    const count = new Array(26).fill(0);

    for (let i = 0; i < str.length; i++) {
      const index = str.charCodeAt(i) - charCodeOfA;
      count[index]++;
    }

    const key = count.join("#");

    if (!groups[key]) {
      groups[key] = [];
    }
    groups[key].push(str);
  }

  return Object.values(groups);
};
