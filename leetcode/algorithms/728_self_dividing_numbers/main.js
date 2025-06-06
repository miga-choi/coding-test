/**
 * @param {number} left
 * @param {number} right
 * @return {number[]}
 */
var selfDividingNumbers = function (left, right) {
  const result = Array();

  for (let i = left; i <= right; i++) {
    let v = i;

    while (v > 0) {
      if (v % 10 == 0 || i % (v % 10) > 0) {
        break;
      }

      v = Math.floor(v / 10);
    }

    if (v == 0) {
      result.push(i);
    }
  }

  return result;
};


// Solution
function isSelfDividingNumber(num) {
  return num
    .toString()
    .split("")
    .map(Number)
    .map((digit) => digit !== 0 && num % digit === 0)
    .reduce((acc, val) => acc && val);
}

var solution = function (left, right) {
  return new Array(right - left + 1)
    .fill(0)
    .map((val, index) => left + index)
    .filter((val) => isSelfDividingNumber(val));
};
