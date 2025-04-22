/**
 * @param {string} a
 * @param {string} b
 * @return {string}
 */
var addBinary = function (a, b) {
  const count = Math.abs(a.length - b.length);
  for (let i = 0; i < count; i++) {
    if (a.length > b.length) {
      b = "0".concat(b);
    } else {
      a = "0".concat(a);
    }
  }
  let result = "";
  let up = 0;
  for (let i = a.length - 1; i >= 0; i--) {
    let num = parseInt(a[i]) + parseInt(b[i]) + up;
    up = 0;
    if (num > 1) {
      num = num - 2;
      up = 1;
    }
    result = String(num).concat(result);
  }
  if (up > 0) {
    result = String(up).concat(result);
  }
  return result;
};


// Solution
// Solution 1
var solution1 = function (a, b) {
  const aBin = `0b${a}`;
  const bBin = `0b${b}`;
  const sum = BigInt(aBin) + BigInt(bBin);
  return sum.toString(2);
};

// Solution 2
var solution2 = function (a, b) {
  return (BigInt("0b" + a) + BigInt("0b" + b)).toString(2);
};
