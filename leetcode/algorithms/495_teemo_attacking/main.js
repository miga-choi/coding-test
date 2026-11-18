/**
 * Pairwise Gap
 *
 * Complexities:
 *   n - The Size of `timeSeries`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var findPoisonedDuration = function (timeSeries, duration) {
  let result = 0;

  for (let i = 1; i < timeSeries.length; i++) {
    if (timeSeries[i] - timeSeries[i - 1] >= duration) {
      result += duration;
    } else {
      result += timeSeries[i] - timeSeries[i - 1];
    }
  }

  result += duration;

  return result;
};


// Solution
/**
 * Solution 1
 *
 * Pairwise Gap
 *
 * Complexities:
 *   n - The Size of `timeSeries`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var solution1 = function (timeSeries, duration) {
  let total = 0;

  for (let i = 0; i < timeSeries.length - 1; i++) {
    total += Math.min(duration, timeSeries[i + 1] - timeSeries[i]);
  }

  return total + duration;
};

/**
 * Solution 2
 *
 * Interval Merging (Track End Time)
 *
 * Complexities:
 *   n - The Size of `timeSeries`
 *   - Time Complexity: O(n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number[]} timeSeries
 * @param {number} duration
 * @return {number}
 */
var solution2 = function (timeSeries, duration) {
  let total = 0;
  let end = 0;

  for (const t of timeSeries) {
    const newEnd = t + duration;

    if (t >= end) {
      total += duration;
    } else {
      total += newEnd - end;
    }

    end = newEnd;
  }

  return total;
};
