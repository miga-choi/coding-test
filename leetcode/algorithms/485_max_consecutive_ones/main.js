/**
 * @param {number[]} nums
 * @return {number}
 */
var findMaxConsecutiveOnes = function (nums) {
  let result = 0;
  let curr = 0;

  for (const num of nums) {
    if (num === 1) {
      curr += 1;
    } else {
      if (curr > result) {
        result = curr;
      }
      curr = 0;
    }
  }

  return Math.max(result, curr);
};


// Best Solution
var bestSolution = function (nums) {
  let max = 0, curr = 0;
  for (let k of nums) {
    max = Math.max(max, (curr += k));
    if (!k) curr = 0;
  }
  return max;
};

var bestSolution1 = function (nums) {
  let max = 0, curr = 0;
  for (let k of nums) {
    max = Math.max(max, (curr += k));
    if (!k) curr = 0;
  }
  return max;
};

var bestSolution2 = function (nums) {
  return nums.join("").split("0").reduce((max, ones) => Math.max(max, ones.length), 0);
};

var bestSolution3 = function (nums) {
  return Math.max(...nums.join("").split("0").map((ones) => ones.length));
};

var bestSolution4 = function (nums) {
  return Math.max(...(nums.join("").match(/1+/g) || [""]).map((ones) => ones.length));
};

var bestSolution5 = function (nums) {
  let str = nums.join(""), max = nums.length + 1;
  while (!~str.indexOf("1".repeat(--max)) && max);
  return max;
};
