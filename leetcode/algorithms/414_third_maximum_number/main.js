/**
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var thirdMax = function (nums) {
  nums = nums.filter((v, i) => i === nums.indexOf(v));

  if (nums.length >= 3) {
    for (let i = 0; i < 2; i++) {
      nums = nums.filter((v) => v < Math.max(...nums));
    }
  }

  return Math.max(...nums);
};


// Solution
/**
 * Solution 1
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution1 = function (nums) {
  let first = -Infinity;
  let second = -Infinity;
  let third = -Infinity;

  for (const num of nums) {
    if (num === first || num === second || num === third) {
      continue;
    }

    if (num > first) {
      third = second;
      second = first;
      first = num;
    } else if (num > second) {
      third = second;
      second = num;
    } else if (num > third) {
      third = num;
    }
  }

  return third === -Infinity ? first : third;
};

/**
 * Solution 2
 *
 * Set + Sorting
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution2 = function (nums) {
  const unique = [...new Set(nums)].sort((a, b) => b - a);
  return unique.length >= 3 ? unique[2] : unique[0];
};

/**
 * Solution 3
 *
 * Sorted Buffer of Size 3
 *
 * Complexities:
 *   N - The Size of `nums`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums
 * @return {number}
 */
var solution3 = function (nums) {
  const top = [];

  for (const num of nums) {
    if (top.includes(num)) {
      continue;
    }

    top.push(num);
    top.sort((a, b) => b - a);

    if (top.length > 3) {
      top.pop();
    }
  }

  return top.length === 3 ? top[2] : top[0];
};
