/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var canConstruct = function (ransomNote, magazine) {
  const magazineMap = new Map();

  for (const v of magazine) {
    if (magazineMap.get(v)) {
      magazineMap.set(v, magazineMap.get(v) + 1);
    } else {
      magazineMap.set(v, 1);
    }
  }

  for (const v of ransomNote) {
    if (magazineMap.get(v) && magazineMap.get(v) > 0) {
      magazineMap.set(v, magazineMap.get(v) - 1);
    } else {
      return false;
    }
  }

  return true;
};


// Solution
var solution = function (ransomNote, magazine) {
  for (const char of magazine) {
    ransomNote = ransomNote.replace(char, "");
  }

  if (!ransomNote) {
    return true;
  } else {
    return false;
  }
};
