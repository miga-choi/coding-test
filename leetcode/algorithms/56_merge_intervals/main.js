/**
 * Sorting
 *
 * Complexities:
 *   N - Length of in `intervals`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var merge = function (intervals) {
  intervals = intervals.sort((p, n) => p[0] - n[0]);

  const result = [];
  result.push(intervals[0]);

  for (let i = 1; i < intervals.length; i++) {
    const last = result[result.length - 1];
    const curr = intervals[i];

    if (last[1] >= curr[0]) {
      if (last[1] < curr[1]) {
        last[1] = curr[1];
      }
    } else {
      result.push(intervals[i]);
    }
  }

  return result;
};


// Solution
/**
 * Sorting
 *
 * Complexities:
 *   N - Length of in `intervals`
 *   - Time Complexity: O(N * logᴺ)
 *   - Space Complexity: O(N)
 */
/**
 * @param {number[][]} intervals
 * @return {number[][]}
 */
var solution = function (intervals) {
  intervals.sort((a, b) => a[0] - b[0]);

  const merged = [intervals[0]];

  for (let i = 1; i < intervals.length; i++) {
    const current = intervals[i];
    const lastMerged = merged[merged.length - 1];

    if (current[0] <= lastMerged[1]) {
      lastMerged[1] = Math.max(lastMerged[1], current[1]);
    } else {
      merged.push(current);
    }
  }

  return merged;
};
