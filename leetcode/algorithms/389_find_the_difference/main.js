/**
 * @param {string} s
 * @param {string} t
 * @return {character}
 */
var findTheDifference = function (s, t) {
  for (const c of s) {
    t = t.replace(c, "");
  }
  return t;
};


// Solution
var solution = function (s, t) {
  for (let letter of s) {
    t = t.replace(letter, "");
  }
  return t;
};
