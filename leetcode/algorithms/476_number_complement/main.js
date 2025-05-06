/**
 * @param {number} num
 * @return {number}
 */
var findComplement = function (num) {
  const binary = num.toString(2).split("");
  let result = "";

  for (const i of binary) {
    if (i === "1") {
      result += "0";
    } else {
      result += "1";
    }
  }

  return parseInt(result, 2);
};


// Solution
var solution = function (num) {
  let d = 2;
  while (d <= num) {
    d *= 2;
  }
  return d - num - 1;
};
