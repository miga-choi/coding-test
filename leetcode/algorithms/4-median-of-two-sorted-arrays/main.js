/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number}
 */
var findMedianSortedArrays = function (nums1, nums2) {
  let nums = nums1.concat(nums2).sort((prev, next) => prev - next);
  if (nums.length % 2 === 1) {
    return nums[Math.round(nums.length / 2) - 1];
  } else {
    return (nums[nums.length / 2 - 1] + nums[nums.length / 2]) / 2;
  }
};
