/**
 * @param {number} x
 * @return {number}
 */
var mySqrt = function (x) {
  for (let i = 0; i <= x; i++) {
    if (i * i <= x && (i + 1) * (i + 1) > x) {
      return i;
    }
  }
};


// Solution
// Solution 1
var solution1 = function (x) {
  var left = 1;
  var right = Math.floor(x / 2) + 1;
  var mid;

  while (left <= right) {
    mid = Math.floor((left + right) / 2);

    if (mid * mid > x) {
      right = mid - 1;
    } else if (mid * mid < x) {
      left = mid + 1;
    } else {
      return mid;
    }
  }

  return right;
};

// Solution 2
var solution2 = function (x) {
  let result = 1;
  while (result * result <= x) {
    result++;
  }
  return result - 1;
};

// Solution 3
var solution3 = function (x) {
  let start = 0;
  let end = x;
  let res = 0;

  while (start < end) {
    res = Math.ceil((start + end) / 2); // 1.

    if (res * res <= x && (res + 1) * (res + 1) > x) {
      return res; // 2.
    }

    if (res * res < x) {
      start = res; // 3.
    } else {
      end = res; // 4.
    }
  }

  return res;
};
