/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var reverseStr = function (s, k) {
  const sArray = s.split("");
  if (sArray.length < k) {
    return sArray.reverse().join("");
  }

  let result = "";

  for (let i = 0; i < s.length; i += 2 * k) {
    const stringK = sArray.slice(i, i + k).reverse().join("");
    const left = sArray.slice(i + k, i + 2 * k).join("");
    result += stringK + left;
  }

  return result;
};


// Best Solution
var bestSolution = function (s, k) {
  if (k > s.length) {
    return s.split("").reverse().join("");
  }

  const split = s.split("");

  // reverse the segment and put it back
  for (let i = 0; i < s.length; i += 2 * k) {
    const reverse = split.splice(i, k).reverse();
    split.splice(i, 0, ...reverse);
  }

  return split.join("");
};
