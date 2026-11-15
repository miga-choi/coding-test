/**
 * Square Root Descent
 *
 * Complexities:
 *   n - `area`
 *   - Time Complexity: O(√n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} area
 * @return {number[]}
 */
var constructRectangle = function (area) {
  let w = Math.floor(Math.sqrt(area));

  while (area % w !== 0) {
    w--;
  }

  return [area / w, w];
};


// Solution
/**
 * Solution 1
 *
 * Square Root Descent
 *
 * Complexities:
 *   n - `area`
 *   - Time Complexity: O(√n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} area
 * @return {number[]}
 */
var solution1 = function (area) {
  let w = Math.floor(Math.sqrt(area));

  while (area % w !== 0) {
    w--;
  }

  return [area / w, w];
};

/**
 * Solution 2
 *
 * Upward Divisor Scan
 *
 * Complexities:
 *   n - `area`
 *   - Time Complexity: O(√n)
 *   - Space Complexity: O(1)
 */
/**
 * @param {number} area
 * @return {number[]}
 */
var solution2 = function (area) {
  let best = 1;

  for (let w = 1; w * w <= area; w++) {
    if (area % w === 0) {
      best = w;
    }
  }

  return [area / best, best];
};
