/**
 * Complexities:
 *   N - The size of `pattern`
 *   M - The size of `s`
 *   - Time Complexity: O(N * M)
 *   - Space Complexity: O(N + M)
 */
/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var wordPattern = function (pattern, s) {
  const sArray = s.split(" ");

  if (sArray.length !== pattern.length) {
    return false;
  }

  const patternMap = new Map();

  for (let i = 0; i < sArray.length; i++) {
    if (patternMap.get(pattern[i])) {
      if (patternMap.get(pattern[i]) !== sArray[i]) {
        return false;
      }
    } else {
      for (const [key, value] of patternMap.entries()) {
        if (value === sArray[i]) {
          return false;
        }
      }
      patternMap.set(pattern[i], sArray[i]);
    }
  }

  return true;
};


// Solution
/**
 * Complexities:
 *   N - The number of characters' length in `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} pattern
 * @param {string} s
 * @return {boolean}
 */
var solution = function (pattern, str) {
  const words = s.split(" ");

  if (pattern.length !== words.length) {
    return false;
  }

  const charToWord = new Map();
  const wordToChar = new Map();

  for (let i = 0; i < pattern.length; i++) {
    const char = pattern[i];
    const word = words[i];

    if (charToWord.has(char)) {
      if (charToWord.get(char) !== word) return false;
    } else {
      charToWord.set(char, word);
    }

    if (wordToChar.has(word)) {
      if (wordToChar.get(word) !== char) return false;
    } else {
      wordToChar.set(word, char);
    }
  }

  return true;
};
