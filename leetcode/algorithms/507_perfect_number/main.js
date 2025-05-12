/**
 * @param {number} num
 * @return {boolean}
 */
var checkPerfectNumber = function (num) {
  if (num <= 1) {
    return false;
  }

  let sum = 0;
  for (let i = 1; i < Math.floor(num / 2); i++) {
    if (num % i === 0) {
      sum += i;
    }
  }

  return sum * 2 === num;
};


// Solution
var solution = function (num) {
  if (num <= 1) {
    return false;
  }

  let divisorsSum = 0;
  for (let i = 1; i <= Math.floor(Math.sqrt(num)); i++) {
    if (num % i === 0) {
      divisorsSum += i + num / i;
    }
  }

  return divisorsSum === 2 * num ? true : false;
};
