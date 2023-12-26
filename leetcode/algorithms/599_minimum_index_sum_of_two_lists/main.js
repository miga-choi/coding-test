/**
 * @param {string[]} list1
 * @param {string[]} list2
 * @return {string[]}
 */
var findRestaurant = function (list1, list2) {
  let result = [];

  const map1 = new Map();
  const map2 = new Map();
  const map3 = new Map();

  for (let i = 0; i < list1.length; i++) {
    map1.set(list1[i], i);
  }

  for (let i = 0; i < list2.length; i++) {
    map2.set(list2[i], i);
  }

  for (const v of list1) {
    if (map1.get(v) >= 0 && map2.get(v) >= 0) {
      map3.set(v, map1.get(v) + map2.get(v));
    }
  }

  const minIndex = Math.min.apply(null, Array.from(map3.values()));

  map3.forEach((v, k) => {
    if (v === minIndex) {
      result.push(k);
    }
  });

  return result;
};


// Best Solution
// Best Solution 1
var bestSolution1 = function (list1, list2) {
  let out = [];
  let obj = new Map();
  list2.forEach((v, i) => obj.set(v, i));
  let i = 0,
    min = Infinity;
  while (i < list1.length) {
    if (obj.has(list1[i])) {
      let sum = i + obj.get(list1[i]);
      if (min === sum) {
        out.push(list1[i]);
      } else if (sum < min) {
        out = [list1[i]];
        min = sum;
      }
    }
    i++;
  }

  return out;
};

// Best Solution 2
var bestSolution2 = function (list1, list2) {
  const map = new Map();
  let ret = [];
  let min = Infinity;
  for (let i = 0; i < list1.length; ++i) {
    map.set(list1[i], i);
  }
  for (let i = 0; i < list2.length; ++i) {
    if (map.has(list2[i])) {
      let index1 = map.get(list2[i]);
      let index2 = i;
      ret.push({ val: list2[i], index: index1 + index2 });
      min = Math.min(min, index1 + index2);
    }
  }
  // Basically ret should be map as well instead of array
  // so we don't have to filter it (it will be faster).
  return ret.filter((item) => item.index === min).map((item) => item.val);
};
