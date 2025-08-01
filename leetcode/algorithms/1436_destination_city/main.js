/**
 * Set
 * - Time Complexity: O(N)
 * - Space Complexity: O(N)
 *
 * @param {string[][]} paths
 * @return {string}
 */
var destCity = function (paths) {
  const cities = new Set();

  for (const path of paths) {
    cities.add(path[0]);
  }

  for (const path of paths) {
    const destination = path[1];
    if (!cities.has(destination)) {
      return destination;
    }
  }

  return "";
};


// Solution
var solution = function (paths) {
  const cities = new Set();

  // Collect outgoing cities
  for (const path of paths) {
    cities.add(path[0]);
  }

  // Find destination city with no outgoing path
  for (const path of paths) {
    const dest = path[1];
    if (!cities.has(dest)) {
      return dest;
    }
  }

  return "";
};
