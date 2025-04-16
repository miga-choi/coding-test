/**
 * @param {string} s
 * @return {boolean}
 */
var validPalindrome = function (s) {
  let left = 0;
  let right = s.length - 1;
  let changed = false;

  while (left < right) {
    if (s[left] === s[right]) {
      left++;
      right--;
    } else {
      if (!changed) {
        if (s[left + 1] == s[right]) {
          left++;
          changed = true;
          continue;
        }
      }
      break;
    }
  }

  if (left >= right) {
    return true;
  }

  left = 0;
  right = s.length - 1;
  changed = false;

  while (left < right) {
    if (s[left] === s[right]) {
      left++;
      right--;
    } else {
      if (!changed) {
        if (s[right - 1] == s[left]) {
          right--;
          changed = true;
          continue;
        }
      }
      break;
    }
  }

  return left >= right;
};


// Solution
var solution = function (s) {
    let low = 0, high = s.length - 1;
    while (low < high) {
        if (s[low] !== s[high]) {
            return isPalindrome(s, low + 1, high) || isPalindrome(s, low, high - 1);
        }
        low++, high--;
    }
    return true;
    // T.C: O(N)
    // S.C: O(1)
};

function isPalindrome(str, low, high) {
    while (low < high) {
        if (str[low] !== str[high]) {
            return false;
        }
        low++, high--;
    }
    return true;
}
