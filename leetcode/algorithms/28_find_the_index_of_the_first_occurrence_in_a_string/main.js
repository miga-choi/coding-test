/**
 * @param {string} haystack
 * @param {string} needle
 * @return {number}
 */
var strStr = function (haystack, needle) {
  return haystack.indexOf(needle);
};


// Solution
// Solution 1: Built-in function
var solution1 = function (haystack, needle) {
  if (needle === "" || needle === haystack) {
    return 0; // the only mandatory check here is (needle === '')
  }
  if (haystack.length < needle.length) {
    return -1; // the other ones are for efficiency
  }

  for (let i = 0; i < haystack.length - needle.length + 1; i++) {
    // start looping through haystack until the remaining substring is shorter than needle
    if (haystack[i] === needle[0]) {
      // as soon as we see a character that matches the first character of needle
      for (let j = 0; j < needle.length; j++) {
        // start looping through both needle and haystack
        if (needle[j] !== haystack[i + j]) {
          // as soon as the characters don't match
          break; // break out of the loop and return to looping through haystack
        } else if (j === needle.length - 1) {
          // otherwise, if we looped through the entire needle and all of the characters matched
          return i; // return the index of the first character of haystack with which we started the loop
        }
      }
    }
  }

  return -1; // return -1 if there wasn't a match
};

// Solution 2: Built-in function
var solution2 = function (haystack, needle) {
  return haystack.indexof(needle);
};

// Solution 3: Find Position with Regex
var solution3 = function (haystack, needle) {
  const regex = new RegExp(needle);
  return haystack.search(regex);
};

/**
 * Solution 4: Brute Force Time: O(N*M)
 * Loop through the haystack. For each character, loop through the needle and compare.
 * If they are all equal, return the index of the haystack
 */
var solution4 = function (haystack, needle) {
  if (!needle) {
    return 0;
  }
  for (let i = 0; i < haystack.length; i++) {
    let isMatch = true;
    for (let j = 0; j < needle.length; j++) {
      if (haystack[i + j] !== needle[j]) {
        isMatch = false;
        break;
      }
    }
    if (isMatch) {
      return i;
    }
  }
  return -1;
};

/**
 * Best Solution 5: Loop through haystack and compare substrings
 * Loop through the haystack. For each character, loop through the needle and compare.
 * If they are all equal, return the index of the haystack
 */
var bestSolution5 = function (haystack, needle) {
  let haystackLength = haystack.length;
  let needleLength = needle.length;
  if (haystackLength < needleLength) {
    return -1;
  }

  for (let i = 0; i <= haystackLength - needleLength; i++) {
    if (haystack.substr(i, needleLength) === needle) {
      return i;
    }
  }
  return -1;
};

/**
 * Best Solution 6: Tracking Loop Search
 * Loop through the haystack string and compare each character
 * of the substring to the corresponding character in the haystack.
 * If all characters match, the index is returned.
 * If the substring is not found, return -1.
 */
var bestSolution6 = function (haystack, needle) {
  let haystackLength = haystack.length;
  let needleLength = needle.length;
  if (haystackLength < needleLength) {
    return -1;
  }

  let matchingIndex = 0;
  for (let i = 0; i < haystackLength; i++) {
    if (needle[i - matchingIndex] !== haystack[i]) {
      i = matchingIndex;
      matchingIndex = i + 1;
    } else if (i - matchingIndex == needleLength - 1) {
      return matchingIndex;
    }
  }
  return -1;
};

/**
 * Best Solution 7: KMP - Time: O(N+M) | KMP - Knuth-Morris-Pratt String Matching Algorithm
 * Preprocess the needle to form an array to store the occurs before.
 * Loop through the haystack and compare with needle.
 * If mismatch occurs, move the haystack index by the occurs before array.
 */
var bestSolution7 = function (haystack, needle) {
  const needleLength = needle.length;
  let i = 0,
    j = -1;

  // LPS - Longest Prefix Suffix / Prefix table
  const lps = [-1];
  while (i < needleLength - 1) {
    if (j === -1 || needle[i] === needle[j]) {
      i++;
      j++;
      lps[i] = j;
    } else {
      j = lps[j];
    }
  }

  (i = 0), (j = 0);
  while (i < haystack.length && j < needleLength) {
    if (haystack[i] === needle[j]) {
      i++;
      j++;
    } else {
      j = lps[j];
      if (j < 0) {
        i++;
        j++;
      }
    }
  }
  if (j === needleLength) {
    return i - j;
  }
  return -1;
};
