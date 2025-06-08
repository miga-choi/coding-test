/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @param {number} newColor
 */
var paint = function (image, sr, sc, color, newColor) {
  if (sr < 0 || sc < 0 || sr >= image.length || sc >= image[0].length) {
    return;
  }

  if (image[sr][sc] != color) {
    return;
  }

  image[sr][sc] = newColor;

  paint(image, sr - 1, sc, color, newColor);
  paint(image, sr + 1, sc, color, newColor);
  paint(image, sr, sc - 1, color, newColor);
  paint(image, sr, sc + 1, color, newColor);
};

/**
 * @param {number[][]} image
 * @param {number} sr
 * @param {number} sc
 * @param {number} color
 * @return {number[][]}
 */
var floodFill = function (image, sr, sc, color) {
  if (image[sr][sc] != color) {
    paint(image, sr, sc, image[sr][sc], color);
  }

  return image;
};


// Solution
var fill = function (image, sr, sc, color, cur) {
  // If sr is less than 0 or greater equals to the length of image
  // Or, If sc is less than 0 or greater equals to the length of image[0]
  if (sr < 0 || sr >= image.length || sc < 0 || sc >= image[0].length) {
    return;
  }

  // If image[sr][sc] is not equal to previous color
  if (cur != image[sr][sc]) {
    return;
  }

  // Update the image[sr][sc] as a color
  image[sr][sc] = color;

  // Make four recursive calls to the function
  // with (sr-1, sc), (sr+1, sc), (sr, sc-1) and (sr, sc+1)
  fill(image, sr - 1, sc, color, cur);
  fill(image, sr + 1, sc, color, cur);
  fill(image, sr, sc - 1, color, cur);
  fill(image, sr, sc + 1, color, cur);
};

var solution = function (image, sr, sc, color) {
  // Avoid infinite loop if the new and old colors are the same
  if (image[sr][sc] == color) {
    return image;
  }

  // Run the fill function starting at the position given
  fill(image, sr, sc, color, image[sr][sc]);

  return image;
};
