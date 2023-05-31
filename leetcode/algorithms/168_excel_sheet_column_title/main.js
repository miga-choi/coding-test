/**
 * @param {number} columnNumber
 * @return {string}
 */
var convertToTitle = function (columnNumber) {
  const alphabet = [
    'A',
    'B',
    'C',
    'D',
    'E',
    'F',
    'G',
    'H',
    'I',
    'J',
    'K',
    'L',
    'M',
    'N',
    'O',
    'P',
    'Q',
    'R',
    'S',
    'T',
    'U',
    'V',
    'W',
    'X',
    'Y',
    'Z',
  ];

  let result = '';

  while (columnNumber > 0) {
    result = alphabet[(columnNumber - 1) % 26] + result;
    columnNumber = Math.floor((columnNumber - 1) / 26);
  }

  return result;
};

// Best Solution
var bestSolution = function (n) {
  if (n == 0) return null;
  let result = '';
  while (n > 0) {
    let r = n % 26;
    let d = parseInt(n / 26);
    if (r == 0) {
      r = 26;
      d = d - 1;
    }
    result += String.fromCharCode(64 + r);
    n = d;
  }
  return result.split('').reverse().join('');
};
