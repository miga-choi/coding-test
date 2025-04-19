/**
 * @param {number[]} nums1
 * @param {number} m
 * @param {number[]} nums2
 * @param {number} n
 * @return {void} Do not return anything, modify nums1 in-place instead.
 */
var merge = function (nums1, m, nums2, n) {
  nums1
    .filter((v_, i_) => i_ < m)
    .concat(nums2)
    .sort((p_, n_) => p_ - n_)
    .map((v_, i_) => (nums1[i_] = v_));
};


// Solution
// Solution 1: STL
var solution1 = function (nums1, m, nums2, n) {
  for (let i = m, j = 0; j < n; i++, j++) {
    nums1[i] = nums2[j];
  }
  nums1.sort((a, b) => a - b);
};

// Solution 2: Two Pointer
var solution2 = function (nums1, m, nums2, n) {
  let i = m - 1;
  let j = n - 1;
  let k = m + n - 1;

  while (j >= 0) {
    if (i >= 0 && nums1[i] > nums2[j]) {
      nums1[k--] = nums1[i--];
    } else {
      nums1[k--] = nums2[j--];
    }
  }
};

// Solution 3:
var solution3 = function (nums1, m, nums2, n) {
  // Initialize i and j to store indices of the last element of 1st and 2nd array respectively...
  let i = m - 1, j = n - 1;

  // Initialize a variable k to store the last index of the 1st array...
  let k = m + n - 1;

  // Create a loop until either of i or j becomes zero...
  while (i >= 0 && j >= 0) {
    if (nums1[i] >= nums2[j]) {
      nums1[k] = nums1[i];
      i--;
    } else {
      nums1[k] = nums2[j];
      j--;
    }
    k--;
    // Either of i or j is not zero, which means some elements are yet to be merged.
    // Being already in a sorted manner, append them to the 1st array in the front.
  }

  // While i does not become zero...
  while (i >= 0) {
    nums1[k--] = nums1[i--];
  }

  // While j does not become zero...
  while (j >= 0) {
    nums1[k--] = nums2[j--];
  }

  // Now 1st array has all the elements in the required sorted order...
  return;
};
