/**
 * @param {number} n
 * @return {number[]}
 */
var countBits = function (n) {
  let result = [];
  for (let i = 0; i <= n; i++) {
    let sum = 0;
    const bits = i.toString(2);
    for (j = 0; j < bits.length; j++) {
      sum += parseInt(bits[j]);
    }
    result.push(sum);
  }
  return result;
};


// Solution
const solution = (n) => {
  let result = Array(n + 1).fill(0);
  let offset = 1;
  for (let i = 1; i < n + 1; i++) {
    if (offset * 2 === i) {
      offset = i;
    }
    result[i] = 1 + result[i - offset];
  }
  return result;
};
