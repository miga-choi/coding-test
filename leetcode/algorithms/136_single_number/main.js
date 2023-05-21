/**
 * @param {number[]} nums
 * @return {number}
 */
var singleNumber = function (nums) {
  let index = 0;
  while (index < nums.length) {
    const findIndex = nums
      .filter((v_, i_) => i_ !== index)
      .findIndex((v_) => v_ === nums[index]);
    if (findIndex === -1) {
      return nums[index];
    }
    index++;
  }
};

// Best Solution
var bestSolution = function (nums) {
  // Initialize the unique number...
  let uniqNum = 0;
  // TRaverse all elements through the loop...
  for (let idx = 0; idx < nums.length; idx++) {
    // Concept of XOR...
    uniqNum = uniqNum ^ nums[idx];
  }
  return uniqNum; // Return the unique number...
};
