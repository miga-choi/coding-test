/**
 * @param {number[]} digits
 * @return {number[]}
 */
var plusOne = function (digits) {
  digits.reverse();
  let up = 0;
  for (let i = 0; i < digits.length; i++) {
    let result = digits[i] + up;
    up = 0;
    if (i === 0) {
      result += 1;
    }
    if (result >= 10) {
      up = 1;
      digits[i] = result - 10;
    } else {
      digits[i] = result;
    }
  }
  if (up > 0) {
    digits.push(up);
  }
  return digits.reverse();
};

// Best Solution
var bestSolution = function (digits) {
  for (var i = digits.length - 1; i >= 0; i--) {
    digits[i]++;
    if (digits[i] > 9) {
      digits[i] = 0;
    } else {
      return digits;
    }
  }
  digits.unshift(1);
  return digits;
};
