/**
 * @param {string} s
 * @return {number}
 */
var lengthOfLongestSubstring = function (s) {
  const charMap = Array(128).fill(-1);
  let left = 0;
  let maxLength = 0;

  for (let right = 0; right < s.length; right++) {
    const currentChar = s[right];

    if (charMap[currentChar] >= left) {
      left = charMap[currentChar] + 1;
    }

    charMap[currentChar] = right;

    maxLength = Math.max(maxLength, right - left + 1);
  }

  return maxLength;
};


// Solution
// Solution 1: Sliding Window & Set
var solution1 = function (s) {
  let left = 0;
  let maxLength = 0;
  let charSet = new Set();

  for (let right = 0; right < s.length; right++) {
    while (charSet.has(s[right])) {
      charSet.delete(s[left]);
      left++;
    }

    charSet.add(s[right]);
    maxLength = Math.max(maxLength, right - left + 1);
  }

  return maxLength;
};

// Solution 2: Sliding Window and Hashing
var solution2 = function (s) {
  let maxLength = 0;
  let left = 0;
  let count = {};

  for (let right = 0; right < s.length; right++) {
    let c = s[right];
    count[c] = (count[c] || 0) + 1;

    while (count[c] > 1) {
      count[s[left]] -= 1;
      left++;
    }

    maxLength = Math.max(maxLength, right - left + 1);
  }

  return maxLength;
};

// Solution 3: the last position where each character was seen
var solution3 = function (s) {
  let maxLength = 0;
  let left = 0;
  let lastSeen = {};

  for (let right = 0; right < s.length; right++) {
    let c = s.charAt(right);
    if (c in lastSeen && lastSeen[c] >= left) {
      left = lastSeen[c] + 1;
    }
    maxLength = Math.max(maxLength, right - left + 1);
    lastSeen[c] = right;
  }

  return maxLength;
};
