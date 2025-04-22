/**
 * @param {number} num
 * @return {number}
 */
var addDigits = function (num) {
  let numString = num.toString();
  while (numString.length > 1) {
    let num = 0;
    for (const num_ of numString) {
      num += parseInt(num_);
    }
    numString = num.toString();
  }
  return numString;
};


// Solution
var solution = function (num) {
  return 1 + ((num - 1) % 9);
};
