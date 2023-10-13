/**
 * @param {number} x
 * @param {number} y
 * @return {number}
 */
var hammingDistance = function (x, y) {
  let xBinary = x.toString(2);
  let yBinary = y.toString(2);
  const length = Math.max(xBinary.length, yBinary.length);
  xBinary = xBinary.padStart(length, "0");
  yBinary = yBinary.padStart(length, "0");
  let result = 0;
  for (let i = 0; i < length; i++) {
    if (xBinary[i] !== yBinary[i]) {
      result++;
    }
  }
  return result;
};


// Best Solution
var bestSolution = function (x, y) {
  return (x ^ y).toString(2).replace(/0/g, "").length;
};
