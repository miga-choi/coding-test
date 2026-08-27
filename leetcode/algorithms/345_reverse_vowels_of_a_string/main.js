/**
 * Two Pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(N)
 */
/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function (s) {
  const vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"];
  const vowelStack = [];
  let result = "";

  for (const c of s) {
    if (vowels.includes(c)) {
      vowelStack.push(c);
    }
  }

  for (let i = 0; i < s.length; i++) {
    if (vowels.includes(s[i])) {
      result += vowelStack.pop();
    } else {
      result += s[i];
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Two Pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(N)
 */
/**
 * @param {string} s
 * @return {string}
 */
var solution1 = function (s) {
  const vowels = new Set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]);
  const arr = s.split("");
  let left = 0;
  let right = arr.length - 1;

  while (left < right) {
    while (left < right && !vowels.has(arr[left])) {
      left++;
    }
    while (left < right && !vowels.has(arr[right])) {
      right--;
    }

    if (left < right) {
      [arr[left], arr[right]] = [arr[right], arr[left]];
      left++;
      right--;
    }
  }

  return arr.join("");
};

/**
 * Solution 2
 *
 * Two Pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(N)
 */
/**
 * @param {string} s
 * @return {string}
 */
const isVowel = (c) => "aeiou".includes(c.toLowerCase());

var solution2 = function (s) {
  const vowels = new Set(["a", "e", "i", "o", "u", "A", "E", "I", "O", "U"]);
  const arr = s.split("");
  let left = 0;
  let right = arr.length - 1;

  while (left < right) {
    while (left < right && !vowels.has(arr[left])) {
      left++;
    }
    while (left < right && !vowels.has(arr[right])) {
      right--;
    }

    if (left < right) {
      [arr[left], arr[right]] = [arr[right], arr[left]];
      left++;
      right--;
    }
  }

  return arr.join("");
};

/**
 * Solution 3
 *
 * Two Pointers
 *
 * Complexities:
 *   N - The size of `s`
 *   - Time Complexities: O(N)
 *   - Space Complexities: O(N)
 */
/**
 * @param {string} s
 * @return {string}
 */
var solution3 = function (s) {
  const vowels = new Set("aeiouAEIOU");
  const found = [];

  for (const c of s) {
    if (vowels.has(c)) {
      found.push(c);
    }
  }

  let idx = found.length - 1;
  return s.replace(/[aeiouAEIOU]/g, () => found[idx--]);
};
