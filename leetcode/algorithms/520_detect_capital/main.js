/**
 * @param {string} word
 * @return {boolean}
 */
var detectCapitalUse = function (word) {
  return word === word.toUpperCase() || word === word.toLowerCase() || word === word.substring(0, 1).toUpperCase() + word.substring(1).toLowerCase();
};


// Best Solution
var bestSolution = function (word) {
  return word === word.toUpperCase() || word === word[0] + word.substr(1).toLowerCase();
};
