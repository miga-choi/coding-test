/**
 * @param {number[]} nums
 * @param {number} val
 * @return {number}
 */
var removeElement = function (nums, val) {
  const newNums = nums.filter((num) => num != val).sort((p, n) => n - p);
  for (let i = 0; i < newNums.length; i++) {
    nums[i] = newNums[i];
  }
  nums.length = newNums.length;
  return nums.length;
};


// Solution
// Solution 1
var solution1 = function (nums, val) {
  var zeroStartIdx = 0;
  for (let i = 0; i < nums.length; i++) {
    if (nums[i] !== val) {
      nums[zeroStartIdx] = nums[i];
      zeroStartIdx++;
    }
  }
  return zeroStartIdx;
};

// Solution 2
var solution2 = function (nums, val) {
  let left = 0;
  let right = nums.length - 1;

  while (left <= right) {
    if (nums[left] === val) {
      nums[left] = nums[right];
      right--;
    } else {
      left++;
    }
  }

  return left;
};

// Solution 3
var solution3 = function (nums, val) {
  // Counter for keeping track of elements other than val
  let count = 0;
  // Loop through all the elements of the array
  for (let i = 0; i < nums.length; i++) {
    // If the element is not val
    if (nums[i] !== val) {
      nums[count++] = nums[i];
    }
  }
  return count;
};
