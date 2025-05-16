/**
 * @param {number[]} nums
 * @return {number}
 */
var findLHS = function (nums) {
  let result = 0;

  const numsSet = new Set(nums);

  if (numsSet.size > 1) {
    const numsMap = new Map();

    for (const num of numsSet) {
      numsMap.set(num, nums.filter((v) => v === num).length);
    }

    numsMap.forEach((v, k) => {
      const l = numsMap.get(k - 1) ?? 0;
      const r = numsMap.get(k + 1) ?? 0;
      if (l > 0 || r > 0) {
        result = Math.max(result, l + v, r + v);
      }
    });
  }

  return result;
};


// Solution
// Solution1: Hash table / Hash map
var solution1 = function (nums) {
  let map = new Map(), len = 0;

  for (let i = 0; i < nums.length; i++) {
    map.set(nums[i], map.get(nums[i]) + 1 || 1);
  }

  for (const [key, value] of map) {
    if (map.get(key - 1)) {
      len = Math.max(len, map.get(key - 1) + value);
    }
  }

  return len;
};

// Solution2
var solution2 = function (nums) {
  let map = {}, res = 0;

  for (let n of nums) {
    map[n] = ~~map[n] + 1;
  }

  for (let n in map) {
    if (map[+n + 1]) {
      res = Math.max(res, map[n] + map[+n + 1]);
    }
  }

  return res;
};
