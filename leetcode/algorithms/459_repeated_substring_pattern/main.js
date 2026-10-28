/**
 * String Concatenation
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N) ~ O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var repeatedSubstringPattern = function (s) {
  return (
    s
      .slice(1, s.length)
      .concat(s.slice(0, s.length - 1))
      .indexOf(s) >= 0
  );
};


// Solution
/**
 * Solution 1
 *
 * Brute Force
 *
 * Complexities:
 *   N - The Size of `s`
 *   d(N) - The Number of Divisors of N
 *   - Time Complexity: O(N * d(N))
 *   - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var solution1 = function (s) {
  const n = s.length;

  for (let len = 1; len <= n / 2; len++) {
    if (n % len !== 0) continue; // 약수만 검사

    let ok = true;
    for (let i = len; i < n; i++) {
      if (s[i] !== s[i - len]) {
        ok = false;
        break;
      }
    }
    if (ok) return true;
  }

  return false;
};

/**
 * Solution 2
 *
 * String Concatenation
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N) ~ O(N²)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var solution2 = function (s) {
  return (s + s).slice(1, -1).includes(s);
};

/**
 * Solution 3
 *
 * KMP Prefix Function
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N)
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var solution3 = function (s) {
  const n = s.length;
  const lps = new Array(n).fill(0);
  let len = 0;

  for (let i = 1; i < n; ) {
    if (s[i] === s[len]) {
      lps[i++] = ++len;
    } else if (len > 0) {
      len = lps[len - 1];
    } else {
      lps[i++] = 0;
    }
  }

  const L = lps[n - 1];
  return L > 0 && n % (n - L) === 0;
};

/**
 * Solution 4
 *
 * Regular Expression
 *
 * Complexities:
 *   N - The Size of `s`
 *   - Time Complexity: O(N²)+
 *   - Space Complexity: O(N)
 */
/**
 * @param {string} s
 * @return {boolean}
 */
var solution4 = function (s) {
  return /^(.+)\1+$/.test(s);
};
