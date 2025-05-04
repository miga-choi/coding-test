/**
 * @param {number[]} nums
 * @return {number}
 */
var findShortestSubArray = function (nums) {
  const numsCountMap = new Map();
  const numsFirstIndexMap = new Map();

  let maxCount = 0;
  let minSubarrayLength = nums.length;

  for (let i = 0; i < nums.length; i++) {
    if (numsCountMap.get(nums[i]) === undefined) {
      numsCountMap.set(nums[i], 0);
      numsFirstIndexMap.set(nums[i], i);
    }

    const count = numsCountMap.get(nums[i]) + 1;
    numsCountMap.set(nums[i], count);

    if (count > maxCount) {
      maxCount = count;
      minSubarrayLength = i - numsFirstIndexMap.get(nums[i]) + 1;
    } else if (count === maxCount) {
      const subarrayLength = i - numsFirstIndexMap.get(nums[i]) + 1;
      if (subarrayLength < minSubarrayLength) {
        minSubarrayLength = subarrayLength;
      }
    }
  }

  return minSubarrayLength;
};


// Solution
var solution = function (nums) {
  const counts = {};
  const firstIndexes = {};
  const lastIndexes = {};
  let max = 0;

  for (let i = 0; i < nums.length; i++) {
    const k = nums[i];
    counts[k] = (counts[k] || 0) + 1;
    max = Math.max(max, counts[k]);
    if (firstIndexes[k] === undefined) {
      firstIndexes[k] = i;
    }
    lastIndexes[k] = i;
  }

  let res = nums.length;
  for (const k in counts) {
    if (counts[k] === max) {
      res = Math.min(res, lastIndexes[k] - firstIndexes[k] + 1);
    }
  }

  return res;
};
