/**
 * Row Lookup Table + First-Letter Row Check
 *
 * Complexities:
 *   i - Length of iᵗʰ Word in `words`
 *   - Time Complexity: O(Σ lenᵢ²)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function (words) {
  const rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
  const result = [];

  for (let word of words) {
    let row = -1;

    for (const c of word) {
      if (rows[0].indexOf(c.toLowerCase()) >= 0) {
        if (row === -1) {
          row = 0;
        } else if (row !== 0) {
          row = -1;
          break;
        }
      } else if (rows[1].indexOf(c.toLowerCase()) >= 0) {
        if (row === -1) {
          row = 1;
        } else if (row !== 1) {
          row = -1;
          break;
        }
      } else if (rows[2].indexOf(c.toLowerCase()) >= 0) {
        if (row === -1) {
          row = 2;
        } else if (row !== 2) {
          row = -1;
          break;
        }
      }
    }

    if (row > -1) {
      result.push(word);
    }
  }

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Lookup Table (Letter → Row)
 *
 * Complexities:
 *   n - Sum of The Number of Characters in `words`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} words
 * @return {string[]}
 */
var solution1 = function (words) {
  const rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
  const rowOf = new Array(26);

  rows.forEach((row, idx) => {
    for (const c of row) {
      rowOf[c.charCodeAt(0) - 97] = idx;
    }
  });

  return words.filter((word) => {
    const lower = word.toLowerCase();
    const row = rowOf[lower.charCodeAt(0) - 97];

    for (let i = 1; i < lower.length; i++) {
      if (rowOf[lower.charCodeAt(i) - 97] !== row) {
        return false;
      }
    }

    return true;
  });
};

/**
 * Solution 2
 *
 * Set per Row
 *
 * Complexities:
 *   n - Sum of The Number of Characters in `words`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} words
 * @return {string[]}
 */
var solution2 = function (words) {
  const rowSets = ["qwertyuiop", "asdfghjkl", "zxcvbnm"].map((r) => new Set(r));

  return words.filter((word) => {
    const lower = word.toLowerCase();
    return rowSets.some((set) => [...lower].every((c) => set.has(c)));
  });
};

/**
 * Solution 3
 *
 * Bitmask Intersection
 *
 * Complexities:
 *   n - Sum of The Number of Characters in `words`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} words
 * @return {string[]}
 */
var solution3 = function (words) {
  const rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
  const rowBit = new Array(26);

  rows.forEach((row, idx) => {
    for (const c of row) {
      rowBit[c.charCodeAt(0) - 97] = 1 << idx;
    }
  });

  return words.filter((word) => {
    let mask = 0b111;

    for (let i = 0; i < word.length && mask; i++) {
      mask &= rowBit[(word.charCodeAt(i) | 32) - 97];
    }

    return mask !== 0;
  });
};

/**
 * Solution 4
 *
 * Regular Expression
 *
 * Complexities:
 *   n - Sum of The Number of Characters in `words`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string[]} words
 * @return {string[]}
 */
var solution4 = function (words) {
  const regex = /^(?:[qwertyuiop]+|[asdfghjkl]+|[zxcvbnm]+)$/i;
  return words.filter((word) => regex.test(word));
};
