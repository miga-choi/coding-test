/**
 * @param {number} x
 * @return {boolean}
 */
var isPalindrome = function (x) {
  const s = x.toString();
  const length = s.length;

  if (length === 1) {
    return true;
  }
  if (s.startsWith('-') || s.startsWith('0') || s.endsWith('0')) {
    return false;
  }
  if (length % 2 === 0) {
    return checkPalindrome(length / 2 - 1, length / 2);
  } else {
    return checkPalindrome(parseInt(length / 2) - 1, parseInt(length / 2) + 1);
  }

  function checkPalindrome(i1, i2) {
    let ifPalindrome = true;
    while (i1 >= 0 && i2 < length) {
      if (s[i1] !== s[i2]) {
        ifPalindrome = false;
      }
      i1--;
      i2++;
    }
    return ifPalindrome;
  }
};
