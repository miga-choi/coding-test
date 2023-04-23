/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  let result = '';

  for (let i = 0; i < s.length; i++) {
    checkPalindromic(i, i); // for odd string
    checkPalindromic(i, i + 1); // for even string
  }

  function checkPalindromic(left, right) {
    while (left >= 0 && s[left] === s[right]) {
      left--;
      right++;
    }

    // for ran one more left-- and right++
    left++;
    right--;

    if (result.length <= right - left + 1) {
      result = s.slice(left, right + 1);
    }
  }

  return result;
};
