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
  if (s.startsWith("-") || s.startsWith("0") || s.endsWith("0")) {
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


// Best Solution
// Best Solution 1:
var bestSolution1 = function (x) {
  var reverse = 0;
  var copy = x;

  // The loop break when the copy of original number becomes zero
  // Also negative number cannot be a palindrome
  while (copy > 0) {
    const digit = copy % 10;
    reverse = reverse * 10 + digit;
    copy = ~~(copy / 10);
  }

  return reverse == x;
};

// Best Solution 2:
var bestSolution2 = function (x) {
  if (x < 0) {
    return false;
  }

  let rev = 0;
  for (let i = x; i >= 1; i = Math.floor(i / 10)) {
    rev = rev * 10 + (i % 10);
  }
  return rev === x;
};
