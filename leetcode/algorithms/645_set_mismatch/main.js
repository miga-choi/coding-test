/**
 * @param {number[]} nums
 * @return {number[]}
 */
var findErrorNums = function (nums) {
  let duplicatedNum = -1, missedNum = -1;
  for (let i = 1; i <= nums.length; i++) {
    let count = 0;
    for (const num of nums) {
      if (num == i) {
        count++;
      }
    }
    if (count == 2) {
      duplicatedNum = i;
    }
    if (count == 0) {
      missedNum = i;
    }
  }
  return [duplicatedNum, missedNum];
};

// Solution
var findErrorNums = function (nums) {};
