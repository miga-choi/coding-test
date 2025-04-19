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


// Solution
// Solution 1:
var solution1 = function (nums, target) {
  // we might need to inseart at the end
  let lo = 0,
    hi = nums.length;

  // breaks if lo == hi
  while (lo < hi) {
    // always gives the lower mid
    let mid = lo + Math.floor((hi - lo) / 2);
    if (target > nums[mid]) {
      // no way mid is a valid option
      lo = mid + 1;
    } else {
      // it might be possibe to inseart @ mid
      hi = mid;
    }
  }
  return lo;
};

// Solution 2:
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

var solution2 = function (nums, target) {
  return binarySearch(nums, target, 0, nums.length - 1);
};
