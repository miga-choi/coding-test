/**
 * @param {number[]} nums
 * @param {number} target
 * @return {number}
 */
var searchInsert = function (nums, target) {
  const foundIndex = nums.findIndex((v_) => v_ >= target);
  if (foundIndex === -1) {
    return nums.length;
  }
  return foundIndex;
};


// Best Solution
// Best Solution 1:
var bestSolution1 = function (nums, target) {
  let lo = 0, hi = nums.length; // we might need to inseart at the end
  while (lo < hi) {
    // breaks if lo == hi
    let mid = lo + Math.floor((hi - lo) / 2); // always gives the lower mid
    if (target > nums[mid]) {
      lo = mid + 1; // no way mid is a valid option
    } else {
      hi = mid; // it might be possibe to inseart @ mid
    }
  }
  return lo;
};

// Best Solution 2:
var bestSolution2 = function (nums, target) {
  return binarySearch(nums, target, 0, nums.length - 1);
};

function binarySearch(array, target, start, end) {
  // If the target is less then the very last item then insert it at that item index
  // because anything index less then that has already been confirmed to be less then the target.
  // Otherwise insert it at that item index + 1
  // because any index grater then that has already been confirmed to be greater then the target
  if (start > end) {
    return start;
  }

  const midPoint = Math.floor((start + end) / 2);

  // found target
  if (array[midPoint] === target) {
    return midPoint;
  }
  // search the left side
  if (array[midPoint] > target) {
    return binarySearch(array, target, start, midPoint - 1);
  }
  // search the right side
  if (array[midPoint] < target) {
    return binarySearch(array, target, midPoint + 1, end);
  }
}
