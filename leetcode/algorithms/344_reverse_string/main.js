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
// Solution 1: Implementation by mirror image:
var solution1 = function (s) {
  let size = s.length;

  // reverse string by mirror image
  for (let i = 0; i < Math.floor(size / 2); i++) {
    [s[i], s[size - 1 - i]] = [s[size - 1 - i], s[i]];
  }

  return;
};

// Solution 2: Implementation by two pointers:
var solution2 = function (s) {
  // one points to head position, the other points to tail position
  let [left, right] = [0, s.length - 1];

  // reverse string by two pointers
  while (left < right) {
    [s[left], s[right]] = [s[right], s[left]];

    left += 1;
    right -= 1;
  }

  return;
};

// Solution 3: Implementation by recursion:
var solution3 = function (s) {
  function helper(left, right) {
    // base case aka stop condition
    if (left >= right) {
      return;
    }

    // general cases
    [s[left], s[right]] = [s[right], s[left]];

    helper(left + 1, right - 1);
    return;
  }

  helper((left = 0), (right = s.length - 1));
  return;
};
