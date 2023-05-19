/**
 * @param {string} s
 * @return {boolean}
 */
var isPalindrome = function (s) {
  s = s.toLowerCase().replace(/[^a-z0-9]/gi, '');
  i = 0;
  while (i < s.length - 1 - i) {
    if (s[i] !== s[s.length - 1 - i]) {
      return false;
    }
    i++;
  }
  return true;
};

var isPalindrome = function (s) {
  s = s.toLowerCase().replace(/[^a-z0-9]/gi, '');
  for (let i = 0; i < s.length; i++) {
    if (i === s.length - 1 - i) {
      break;
    }
    if (s[i] !== s[s.length - 1 - i]) {
      return false;
    }
  }
  return true;
};

// Best Solution
const bestSolution = (s) => {
  s = s.toLowerCase().replace(/[^a-z0-9]/gi, '');
  for (let i = 0, j = s.length - 1; i <= j; i++, j--) {
    if (s.charAt(i) !== s.charAt(j)) return false;
  }
  return true;
};
