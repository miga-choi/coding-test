/**
 * Sliding Window (Using Array)
 *
 * Complexities:
 *   N - Length of `s`
 *   M - Length of Available Characters in `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(Min(M, N))
 */
/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  const charMap = new Array(128).fill(-1);
  let left = 0;
  let maxLength = 0;

  for (let right = 0; right < s.length; right++) {
    const currentChar = s[right];

    if (charMap[currentChar] >= left) {
      left = charMap[currentChar] + 1;
    }

    charMap[currentChar] = right;

    maxLength = Math.max(maxLength, right - left + 1);
  }

  return maxLength;
};


// Solution
/**
 * Sliding Window (Using Map)
 *
 * Complexities:
 *   N - Length of `s`
 *   M - Length of Available Characters in `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(Min(M, N))
 */
var solution = function (s) {
  const map = new Map();
  let left = 0;
  let maxLength = 0;

  for (let right = 0; right < s.length; right++) {
    const char = s[right];

    if (map.has(char) && map.get(char) >= left) {
      left = map.get(char) + 1;
    }

    map.set(char, right);

    maxLength = Math.max(maxLength, right - left + 1);
  }

  return maxLength;
};
