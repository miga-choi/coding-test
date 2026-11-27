/**
 * Brute Force with Found Flag
 *
 * Complexities:
 *   n - The Size of `nums1`
 *   m - The Size of `nums2`
 *   - Time Complexity: O(n * m)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function (nums1, nums2) {
  const result = [];

  for (let i = 0; i < nums1.length; i++) {
    const index = nums2.indexOf(nums1[i]);
    if (index >= 0) {
      const newNums2 = nums2.slice(index);
      const greater = newNums2.filter((v) => v > nums1[i]);
      if (greater.length > 0) {
        result.push(greater[0]);
      } else {
        result.push(-1);
      }
    } else {
      result.push(-1);
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Brute Force
 *
 * Complexities:
 *   n - The Size of `nums1`
 *   m - The Size of `nums2`
 *   - Time Complexity: O(n * m)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var solution1 = function (nums1, nums2) {
  return nums1.map((x) => {
    const start = nums2.indexOf(x);

    for (let j = start + 1; j < nums2.length; j++) {
      if (nums2[j] > x) {
        return nums2[j];
      }
    }

    return -1;
  });
};

/**
 * Solution 2
 *
 * Monotonic Stack + Hash Map
 *
 * Complexities:
 *   n - The Size of `nums1`
 *   m - The Size of `nums2`
 *   - Time Complexity: O(n + m)
 *   - Space Complexity: O(m)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var solution2 = function (nums1, nums2) {
  const nextGreater = new Map();
  const stack = [];

  for (const cur of nums2) {
    while (stack.length > 0 && stack[stack.length - 1] < cur) {
      nextGreater.set(stack.pop(), cur);
    }
    stack.push(cur);
  }

  return nums1.map((x) => nextGreater.get(x) ?? -1);
};

/**
 * Solution 3
 *
 * Monotonic Stack (Right to Left)
 *
 * Complexities:
 *   n - The Size of `nums1`
 *   m - The Size of `nums2`
 *   - Time Complexity: O(n + m)
 *   - Space Complexity: O(m)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var solution3 = function (nums1, nums2) {
  const nextGreater = new Map();
  const stack = [];

  for (let i = nums2.length - 1; i >= 0; i--) {
    const cur = nums2[i];

    while (stack.length > 0 && stack[stack.length - 1] <= cur) {
      stack.pop();
    }

    nextGreater.set(cur, stack.length > 0 ? stack[stack.length - 1] : -1);
    stack.push(cur);
  }

  return nums1.map((x) => nextGreater.get(x));
};
