/**
 * @param {number[]} nums1
 * @param {number[]} nums2
 * @return {number[]}
 */
var intersect = function (nums1, nums2) {
  const result = [];
  const numsMap = new Map();

  for (const num1 of nums1) {
    if (numsMap[num1]) {
      numsMap[num1] += 1;
    } else {
      numsMap[num1] = 1;
    }
  }

  for (const num2 of nums2) {
    if (numsMap[num2] > 0) {
      result.push(num2);
      numsMap[num2] -= 1;
    }
  }

  return result;
};


// Best Solution
var bestSolution = function (nums1, nums2) {
  const map = new Map();
  for (const n of nums1) {
    if (map.has(n)) {
      map.set(n, map.get(n) + 1);
    } else {
      map.set(n, 1);
    }
  }
  const result = [];
  for (const n of nums2) {
    if (map.has(n) && map.get(n) > 0) {
      result.push(n);
      map.set(n, map.get(n) - 1);
    }
  }
  return result;
};
