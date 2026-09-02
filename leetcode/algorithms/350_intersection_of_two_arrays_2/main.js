/**
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(N + M)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
  const result = [];
  const numsMap = new Map();

  for (const num1 of nums1) {
    if (numsMap[num1]) {
      numsMap[num1] += 1;
    } else {
      numsMap[num1] = 1;
    }
  }

  for (const num2 of nums2) {
    if (numsMap[num2] > 0) {
      result.push(num2);
      numsMap[num2] -= 1;
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Map
 *
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(min(N, M))
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var solution1 = function (nums1, nums2) {
  if (nums1.length > nums2.length) {
    [nums1, nums2] = [nums2, nums1];
  }

  const count = new Map();
  for (const num of nums1) {
    count.set(num, (count.get(num) ?? 0) + 1);
  }

  const result = [];
  for (const num of nums2) {
    const remaining = count.get(num);
    if (remaining > 0) {
      result.push(num);
      count.set(num, remaining - 1);
    }
  }

  return result;
};

/**
 * Solution 2
 *
 * Sorting + Two Pointers
 *
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(max(logᴺ, logᴹ))
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var solution2 = function (nums1, nums2) {
  nums1.sort((a, b) => a - b);
  nums2.sort((a, b) => a - b);

  const result = [];
  let i = 0,
    j = 0;

  while (i < nums1.length && j < nums2.length) {
    if (nums1[i] < nums2[j]) {
      i++;
    } else if (nums1[i] > nums2[j]) {
      j++;
    } else {
      result.push(nums1[i]);
      i++;
      j++;
    }
  }

  return result;
};
