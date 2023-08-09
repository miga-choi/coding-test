/**
 * Definition for isBadVersion()
 *
 * @param {integer} version number
 * @return {boolean} whether the version is bad
 * isBadVersion = function(version) {
 *     ...
 * };
 */

isBadVersion = function (version) {
  return false;
};

/**
 * @param {function} isBadVersion()
 * @return {function}
 */
var solution = function (isBadVersion) {
  /**
   * @param {integer} n Total versions
   * @return {integer} The first bad version
   */
  return function (n) {
    let left = 0;
    let right = n;

    while (left < right) {
      const mid = Math.floor(left + (right - left) / 2);

      if (isBadVersion(mid)) {
        right = mid;
      } else {
        left = mid + 1;
      }
    }

    return left;
  };
};


// Best Solution
var bestSolution = function (isBadVersion) {
  /**
   * @param {integer} n Total versions
   * @return {integer} The first bad version
   */
  return function (n) {
    // binary search
    var start = 1,
      end = n;
    while (start < end) {
      var mid = Math.floor(start + (end - start) / 2);
      if (isBadVersion(mid)) {
        end = mid; // look on left side of mid
      } else {
        start = mid + 1; // look on the right side of mid
      }
    }
    return start;
  };
};
