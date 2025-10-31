/**
 * Expand Around Center
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @param {number} left
 * @param {number} right
 * @return {number}
 */
var getPalindromeLength = function (s, left, right) {
  while (left >= 0 && right < s.length && s[left] === s[right]) {
    left--;
    right++;
  }
  return right - left - 1;
};

/**
 * @param {string} s
 * @return {string}
 */
var longestPalindrome = function (s) {
  if (s.length === 1) {
    return s;
  }

  let startIndex = 0;
  let maxLen = 0;

  for (let i = 0; i < s.length; i++) {
    const oddLen = getPalindromeLength(s, i, i);
    const evenLen = getPalindromeLength(s, i, i + 1);

    const currMaxLen = oddLen > evenLen ? oddLen : evenLen;

    if (currMaxLen > maxLen) {
      maxLen = currMaxLen;
      startIndex = i - Math.floor((maxLen - 1) / 2);
    }
  }

  return s.substring(startIndex, startIndex + maxLen);
};


// Solution
/**
 * Solution 1
 *
 * Expand Around Center
 * - Time Complexity: O(N²)
 * - Space Complexity: O(1)
 */
/**
 * @param {string} s
 * @return {string}
 */
var solution1 = function (s) {
  if (s.length < 2) return s;

  let start = 0;
  let maxLength = 1;

  /**
   * @param {number} left - 시작 왼쪽 포인터
   * @param {number} right - 시작 오른쪽 포인터
   */
  function expandAroundCenter(left, right) {
    // 포인터가 유효 범위 내에 있고, 양쪽 문자가 같을 동안 확장
    while (left >= 0 && right < s.length && s[left] === s[right]) {
      const currentLength = right - left + 1;
      if (currentLength > maxLength) {
        maxLength = currentLength;
        start = left;
      }
      left--;
      right++;
    }
  }

  for (let i = 0; i < s.length; i++) {
    // 홀수 길이 Palindrome (중심이 i)
    expandAroundCenter(i, i);
    // 짝수 길이 Palindrome (중심이 i, i+1)
    expandAroundCenter(i, i + 1);
  }

  return s.substring(start, start + maxLength);
};

/**
 * Solution 2
 *
 * Dynamic Programming
 * - Time Complexity: O(N²)
 * - Space Complexity: O(N²)
 */
/**
 * @param {string} s
 * @return {string}
 */
var solution2 = function (s) {
  if (s.length < 2) {
    return s;
  }

  const n = s.length;
  const dp = Array.from({ length: n }, () => new Array(n).fill(false));

  let start = 0;
  let maxLength = 1;

  // 길이가 1인 경우
  for (let i = 0; i < n; i++) {
    dp[i][i] = true;
  }

  // 길이가 2인 경우
  for (let i = 0; i < n - 1; i++) {
    if (s[i] === s[i + 1]) {
      dp[i][i + 1] = true;
      start = i;
      maxLength = 2;
    }
  }

  // 길이가 3 이상인 경우
  for (let len = 3; len <= n; len++) {
    for (let i = 0; i <= n - len; i++) {
      const j = i + len - 1;

      if (s[i] === s[j] && dp[i + 1][j - 1]) {
        dp[i][j] = true;

        if (len > maxLength) {
          start = i;
          maxLength = len;
        }
      }
    }
  }

  return s.substring(start, start + maxLength);
};
