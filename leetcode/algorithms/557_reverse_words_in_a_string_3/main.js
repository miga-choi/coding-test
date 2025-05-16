/**
 * @param {string} s
 * @return {string}
 */
var reverseWords = function (s) {
  const sArray = s.split(" ");
  for (let i = 0; i < sArray.length; i++) {
    sArray[i] = sArray[i].split("").reverse().join("");
  }
  return sArray.join(" ");
};


// Solution
var solution = function (s) {
  const words = s.split(" ");
  for (let i = 0; i < words.length; i++) {
    words[i] = words[i].split("").reverse().join("");
  }
  return words.join(" ");
};
