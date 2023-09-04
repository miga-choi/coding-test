/**
 * @param {number} num
 * @return {boolean}
 */
var isPerfectSquare = function (num) {
  let i = 0;
  while (true) {
    if (i ** 2 === num) {
      return true;
    } else if (i ** 2 > num) {
      return false;
    } else {
      i++;
    }
  }
};


// Best Solution
var bestSolution = function (num) {
  return num ** 0.5 == parseInt(num ** 0.5);
};
