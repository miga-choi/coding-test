/**
 * Two pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var reverseString = function (s) {
  for (let i = 0; i < s.length / 2; i++) {
    const temp = s[i];
    s[i] = s[s.length - 1 - i];
    s[s.length - 1 - i] = temp;
  }
};


// Solution
/**
 * Solution 1
 *
 * Two pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var solution1 = function (s) {
  let left = 0;
  let right = s.length - 1;

  while (left < right) {
    [s[left], s[right]] = [s[right], s[left]];
    left++;
    right--;
  }
};

/**
 * Solution 2
 *
 * Two pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var solution1 = function (s) {
  for (let left = 0, right = s.length - 1; left < right; left++, right--) {
    const temp = s[left];
    s[left] = s[right];
    s[right] = temp;
  }
};

/**
 * Solution 3
 *
 * Built-in function
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(1)
 */
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var solution3 = function (s) {
  s.reverse();
};

/**
 * Solution 4
 *
 * Recursion
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(N)
 */
/**
 * @param {character[]} s
 * @return {void} Do not return anything, modify s in-place instead.
 */
var solution4 = function (s) {
  if (left >= right) {
    return;
  }

  [s[left], s[right]] = [s[right], s[left]];

  solution4(s, left + 1, right - 1);
};
