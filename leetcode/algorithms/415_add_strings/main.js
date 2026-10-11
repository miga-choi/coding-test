/**
 * Complexities:
 *   N - The Size of `num1`
 *   M - The Size of `num2`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(1)
 */
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
/**
 * Two Pointers
 *
 * Complexities:
 *   N - The Size of `num1`
 *   M - The Size of `num2`
 *   - Time Complexity: O(max(N, M))
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} num1
 * @param {string} num2
 * @return {string}
 */
var solution = function (num1, num2) {
  let i = num1.length - 1;
  let j = num2.length - 1;
  let carry = 0;
  const result = [];

  while (i >= 0 || j >= 0 || carry > 0) {
    const d1 = i >= 0 ? num1.charCodeAt(i) - 48 : 0;
    const d2 = j >= 0 ? num2.charCodeAt(j) - 48 : 0;
    const sum = d1 + d2 + carry;

    result.push(sum % 10);
    carry = Math.floor(sum / 10);

    i--;
    j--;
  }

  return result.reverse().join("");
};
