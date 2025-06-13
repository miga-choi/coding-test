/**
 * @param {character[]} letters
 * @param {character} target
 * @return {character}
 */
var nextGreatestLetter = function (letters, target) {
  if (letters[letters.length - 1] <= target) {
    return letters[0];
  }

  for (let i = 0; i < letters.length; i++) {
    if (letters[i] > target) {
      return letters[i];
    }
  }

  return letters[0];
};


// Solution
var solution = function (letters, target) {
  let lo = 0, hi = letters.length;

  while (lo < hi) {
    const mid = Math.floor((lo + hi) / 2);

    if (letters[mid] <= target) {
      lo = mid + 1;
    } else {
      hi = mid;
    }
  }

  return letters[lo % letters.length];
};
