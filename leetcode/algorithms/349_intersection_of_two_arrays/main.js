/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersection = function (nums1, nums2) {
  const result = [];
  for (const num1 of nums1) {
    if (nums2.indexOf(num1) >= 0) {
      result.push(num1);
    }
  }
  return result.filter((v, i) => result.indexOf(v) === i);
};


// Best Solution
// Brute Force Solution
function bestSolution1(nums1, nums2) {
  let sortedNums1 = nums1.sort((a, b) => a - b);
  let sortedNums2 = nums2.sort((a, b) => a - b);
  let result = [];
  let i = 0;
  let j = 0;

  while (i < sortedNums1.length && j < sortedNums2.length) {
    if (sortedNums1[i] === sortedNums2[j]) {
      if (!result.includes(sortedNums1[i])) result.push(sortedNums1[i]);
      i++;
      j++;
    } else if (sortedNums1[i] < sortedNums2[j]) i++;
    else j++;
  }
  return result;
}

// HashMap Solution
function bestSolution2(nums1, nums2) {
  let map = new Map();
  for (let num of nums1) {
    if (!map.has(num)) map.set(num, 1);
  }

  return nums2.filter((n) => {
    if (map.has(n)) {
      map.delete(n);
      return true;
    } else return false;
  });
}
