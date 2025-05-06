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


// Solution
// Solution 1
var solution = function (nums) {
  let max = 0, curr = 0;
  for (let k of nums) {
    max = Math.max(max, (curr += k));
    if (!k) curr = 0;
  }
  return max;
};

// Solution 2
var solution2 = function (nums) {
  let max = 0, curr = 0;
  for (let k of nums) {
    max = Math.max(max, (curr += k));
    if (!k) curr = 0;
  }
  return max;
};

// Solution 3
var solution3 = function (nums) {
  return nums.join("").split("0").reduce((max, ones) => Math.max(max, ones.length), 0);
};

// Solution 4
var solution4 = function (nums) {
  return Math.max(...nums.join("").split("0").map((ones) => ones.length));
};

// Solution 5
var solution5 = function (nums) {
  return Math.max(...(nums.join("").match(/1+/g) || [""]).map((ones) => ones.length));
};

// Solution 6
var solution6 = function (nums) {
  let str = nums.join(""), max = nums.length + 1;
  while (!~str.indexOf("1".repeat(--max)) && max);
  return max;
};
