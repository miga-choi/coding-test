/**
 * Map
 *
 * Complexities:
 *   N - The Size of `ransomNote`
 *   M - The Size of `magazine`
 *   K - The Size of Characters in `magazine`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(K)
 */
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
/**
 * Solution 1
 *
 * Counting Array
 *
 * Complexities:
 *   N - The Size of `ransomNote`
 *   M - The Size of `magazine`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var solution1 = function (ransomNote, magazine) {
  if (ransomNote.length > magazine.length) {
    return false;
  }

  const count = new Array(26).fill(0);
  const base = "a".charCodeAt(0);

  for (const c of magazine) {
    count[c.charCodeAt(0) - base]++;
  }

  for (const c of ransomNote) {
    const idx = c.charCodeAt(0) - base;

    if (--count[idx] < 0) {
      return false;
    }
  }

  return true;
};

/**
 * Solution 2
 *
 * Map
 *
 * Complexities:
 *   N - The Size of `ransomNote`
 *   M - The Size of `magazine`
 *   K - The Size of Characters in `magazine`
 *   - Time Complexity: O(N + M)
 *   - Space Complexity: O(K)
 */
/**
 * @param {string} ransomNote
 * @param {string} magazine
 * @return {boolean}
 */
var solution2 = function (ransomNote, magazine) {
  const count = new Map();

  for (const c of magazine) {
    count.set(c, (count.get(c) ?? 0) + 1);
  }

  for (const c of ransomNote) {
    const remaining = count.get(c) ?? 0;

    if (remaining === 0) {
      return false;
    }

    count.set(c, remaining - 1);
  }

  return true;
};
