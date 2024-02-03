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
// Best Solution 1:
var bestSolution1 = function (digits) {
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

// Best Solution 2:
var bestSolution2 = function (digits) {
  for (var i = digits.length - 1; i >= 0; i--) {
    if (++digits[i] > 9) {
      digits[i] = 0;
    } else {
      return digits;
    }
  }
  digits.unshift(1);
  return digits;
};

// Best Solution 3:
var bestSolution3 = function (digits) {
  for (let i = digits.length - 1; i >= 0; i--) {
    if (digits[i] === 9) {
      digits[i] = 0;
    } else {
      digits[i]++;
      return digits;
    }
  }
  return [1, ...digits];
};
