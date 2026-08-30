/**
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function (nums1, nums2) {
  const result = [];

  for (const num1 of nums1) {
    if (nums2.indexOf(num1) >= 0) {
      result.push(num1);
    }
  }

  return result.filter((v, i) => result.indexOf(v) === i);
};


// Solution
/**
 * Solution 1
 *
 * Set
 *
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(N + M)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
function solution1(nums1, nums2) {
  if (nums1.length > nums2.length) {
    [nums1, nums2] = [nums2, nums1];
  }

  const set1 = new Set(nums1);
  const result = new Set();

  for (const num of nums2) {
    if (set1.has(num)) result.add(num);
  }

  return [...result];

  // const set1 = new Set(nums1);
  // return [...new Set(nums2)].filter((num) => set1.has(num));
}

/**
 * Solution 2
 *
 * Sort + Two pointers
 *
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N * logᴺ + M * logᴹ)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
function solution2(nums1, nums2) {
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
      if (result.length === 0 || result[result.length - 1] !== nums1[i]) {
        result.push(nums1[i]);
      }
      i++;
      j++;
    }
  }

  return result;
}

/**
 * Solution 3
 *
 * Constraints
 *
 * Complexities:
 *   N - The size of `nums1`
 *   M - The size of `nums2`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
function solution3(nums1, nums2) {
  const seen = new Uint8Array(1001);
  const result = [];

  for (const num of nums1) {
    seen[num] = 1;
  }
  for (const num of nums2) {
    if (seen[num] === 1) {
      result.push(num);
      seen[num] = 2;
    }
  }

  return result;
}
