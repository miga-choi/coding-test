/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var nextGreaterElement = function (nums1, nums2) {
  const result = [];

  for (let i = 0; i < nums1.length; i++) {
    const index = nums2.indexOf(nums1[i]);
    if (index >= 0) {
      const newNums2 = nums2.slice(index);
      const greater = newNums2.filter((v) => v > nums1[i]);
      if (greater.length > 0) {
        result.push(greater[0]);
      } else {
        result.push(-1);
      }
    } else {
      result.push(-1);
    }
  }

  return result;
};


// Solution
// Solution 1: Brute Force
var solution1 = function (nums1, nums2) {
  const ans = [];

  for (let i = 0; i < nums1.length; i++) {
    let max = -1;

    for (let j = 0; j < nums2.length; j++) {
      let index = j;

      if (nums1[i] === nums2[j]) {
        // Found element in nums2 that matches current element in nums1
        while (index !== nums2.length) {
          // Iterate through remaining elements in nums2 to find next greater element
          if (nums2[index] > nums1[i]) {
            // Update max if we find a greater element
            max = nums2[index];
            break;
          }
          index++;
        }
      }
    }

    ans.push(max);
  }

  return ans;
};

// Solution 2: Stack
var solution2 = function (nums1, nums2) {
  // map for next greater element
  const map = new Map();
  const stack = [];

  for (let num of nums2) {
    while (stack.length && stack[stack.length - 1] < num) {
      // Pop elements from stack and update map with next greater element
      map.set(stack.pop(), num);
    }
    // Push current element onto stack
    stack.push(num);
  }

  for (let i = 0; i < nums1.length; i++) {
    // Check if each element in nums1 has a next greater element in map
    // Update element in nums1 with next greater element or -1
    nums1[i] = map.has(nums1[i]) ? map.get(nums1[i]) : -1;
  }

  return nums1;
};
