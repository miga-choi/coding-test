/**
 * Sort + Two-pointer
 * - Time Complexity: O(N²)
 * - Space Complexity: O(logᴺ)
 *
 * @param {number[]} nums
 * @return {number[][]}
 */
var threeSum = function (nums) {
  nums.sort((p, n) => p - n);

  const len = nums.length;
  const result = [];

  for (let flag = 0; flag < len - 2; flag++) {
    if (flag > 0 && nums[flag] === nums[flag - 1]) {
      continue;
    }

    let left = flag + 1;
    let right = len - 1;

    while (left < right) {
      const sum = nums[flag] + nums[left] + nums[right];

      if (sum < 0) {
        left++;
      } else if (sum > 0) {
        right--;
      } else {
        result.push([nums[flag], nums[left], nums[right]]);

        left++;
        right--;

        while (left < right && nums[left] === nums[left - 1]) {
          left++;
        }
        while (left < right && nums[right] === nums[right + 1]) {
          right--;
        }
      }
    }
  }

  return result;
};


// Solution
/**
 * Sort + Two-pointer
 * - Time Complexity: O(N²)
 * - Space Complexity: O(logᴺ)
 *
 * @param {number[]} nums
 * @return {number[][]}
 */
var solution = function (nums) {
  if (nums.length < 3) {
    return [];
  }

  nums.sort((a, b) => a - b);

  const result = [];

  for (let i = 0; i < nums.length - 2; i++) {
    if (nums[i] > 0) {
      break;
    }

    if (i > 0 && nums[i] === nums[i - 1]) {
      continue;
    }

    let left = i + 1;
    let right = nums.length - 1;

    while (left < right) {
      const sum = nums[i] + nums[left] + nums[right];

      if (sum < 0) {
        left++;
      } else if (sum > 0) {
        right--;
      } else {
        result.push([nums[i], nums[left], nums[right]]);

        while (left < right && nums[left] === nums[left + 1]) {
          left++;
        }
        while (left < right && nums[right] === nums[right - 1]) {
          right--;
        }

        left++;
        right--;
      }
    }
  }

  return result;
};
