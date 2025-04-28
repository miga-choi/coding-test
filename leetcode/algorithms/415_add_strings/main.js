/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var addStrings = function (num1, num2) {
  while (num1.length != num2.length) {
    if (num1.length > num2.length) {
      num2 = "0" + num2;
    } else {
      num1 = "0" + num1;
    }
  }

  let result = "";
  let up = 0;

  for (let i = num1.length; i >= 0; i--) {
    const n1 = parseInt(num1[i]);
    const n2 = parseInt(num2[i]);
    let sum = n1 + n2 + up;
    up = 0;

    if (sum > 9) {
      up += 1;
      sum -= 10;
    }

    result += sum.toString();
  }

  return result;
};


// Solution
var solution = function (num1, num2) {
  let i = num1.length - 1;
  let j = num2.length - 1;
  let carry = 0;
  let sum = "";

  for (; i >= 0 || j >= 0 || carry > 0; i--, j--) {
    const digit1 = i < 0 ? 0 : num1.charAt(i) - "0";
    const digit2 = j < 0 ? 0 : num2.charAt(j) - "0";
    const digitsSum = digit1 + digit2 + carry;
    sum = `${digitsSum % 10}${sum}`;
    carry = Math.floor(digitsSum / 10);
  }

  return sum;
};
