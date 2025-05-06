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
var solution = function (area) {
  let w = parseInt(Math.sqrt(area));

  while (!Number.isInteger(area / w)) {
    w--;
  }

  return [area / w, w];
};
