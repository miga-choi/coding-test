/**
 * @param {number[]} nums
 * @return {string[]}
 */
var summaryRanges = function (nums) {
  const result = [];

  if (nums.length > 0) {
    let num = nums[0];
    let numArray = [num];
    for (let i = 1; i < nums.length; i++) {
      console.log(num, nums[i]);
      if (nums[i] - num === 1) {
        numArray.push(nums[i]);
      } else {
        if (numArray.length > 1) {
          result.push(`${numArray[0]}->${numArray[numArray.length - 1]}`);
        } else {
          result.push(`${numArray[0]}`);
        }
        numArray = [nums[i]];
      }

      num = nums[i];
    }

    if (numArray.length > 0) {
      if (numArray.length > 1) {
        result.push(`${numArray[0]}->${numArray[numArray.length - 1]}`);
      } else {
        result.push(`${numArray[0]}`);
      }
    }
  }

  return result;
};


// Best Solution
var bestSolution = function (nums) {
  var t = 0;
  var ans = [];
  nums.push("#");
  for (var i = 1; i < nums.length; i++)
    if (nums[i] - nums[t] !== i - t) {
      if (i - t > 1) ans.push(nums[t] + "->" + nums[i - 1]);
      else ans.push(nums[t].toString());
      t = i;
    }
  return ans;
};
