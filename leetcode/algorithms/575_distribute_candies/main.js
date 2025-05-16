/**
 * @param {number[]} candyType
 * @return {number}
 */
var distributeCandies = function (candyType) {
  candyLength = candyType.length / 2;
  typeLength = candyType.filter((v, i) => i === candyType.indexOf(v)).length;
  return typeLength <= candyLength ? typeLength : candyLength;
};


// Solution
var solution = function (candyType) {
  return Math.min(new Set(candyType).size, candyType.length / 2);
};
