/**
 * @param {string} jewels
 * @param {string} stones
 * @return {number}
 */
var numJewelsInStones = function (jewels, stones) {
  const numsArray = Array(128);
  for (const jewel of jewels) {
    numsArray[jewel.charCodeAt(0)] = 1;
  }

  let count = 0;
  for (const stone of stones) {
    if (numsArray[stone.charCodeAt(0)]) {
      count++;
    }
  }

  return count;
};


// Solution
// Solution 1: Set
var solution1 = function (jewels, stones) {
  const jewelsSet = new Set(jewels);
  return stones.split("").reduce((res, s) => res + jewelsSet.has(s), 0);
};

// Solution 2
var solution2 = (jewels, stones) =>
  stones.split("").filter((char) => jewels.indexOf(char) !== -1).length;
