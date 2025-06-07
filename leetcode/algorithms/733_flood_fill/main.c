#include <stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume
 * caller calls free().
 */
void fill(
  int** image,
  int imageSize, int imageColSize,
  int r, int c,
  int color, int newColor
) {
    if (r < 0 || r >= imageSize || c < 0 || c >= imageColSize) {
        return;
    }

    if (image[r][c] != color) {
        return;
    }

    image[r][c] = newColor;

    fill(image, imageSize, imageColSize, r - 1, c, color, newColor);
    fill(image, imageSize, imageColSize, r + 1, c, color, newColor);
    fill(image, imageSize, imageColSize, r, c - 1, color, newColor);
    fill(image, imageSize, imageColSize, r, c + 1, color, newColor);
}

int** floodFill(
  int** image,
  int imageSize, int* imageColSize,
  int sr, int sc,
  int color,
  int* returnSize, int** returnColumnSizes
) {
    if (image[sr][sc] != color) {
        fill(image, imageSize, imageColSize[sr], sr, sc, image[sr][sc], color);
    }

    *returnSize = imageSize;
    *returnColumnSizes = (int*)malloc(sizeof(int*) * imageSize);

    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    return image;
}


// Solution
void paint(
  int** image,
  int imageSize, int* imageColSize,
  int sr, int sc,
  int newColor, int oldColor
) {
    if (sr < 0 || sr >= imageSize) {
        return;
    }
    if (sc < 0 || sc >= imageColSize[0]) {
        return;
    }

    if (image[sr][sc] == oldColor) {
        image[sr][sc] = newColor;
        paint(image, imageSize, imageColSize, sr - 1, sc, newColor, oldColor);
        paint(image, imageSize, imageColSize, sr + 1, sc, newColor, oldColor);
        paint(image, imageSize, imageColSize, sr, sc - 1, newColor, oldColor);
        paint(image, imageSize, imageColSize, sr, sc + 1, newColor, oldColor);
    }
}

int** solution(
  int** image,
  int imageSize, int* imageColSize,
  int sr, int sc,
  int newColor,
  int* returnSize, int** returnColumnSizes
) {
    *returnSize = imageSize;
    *returnColumnSizes = malloc(sizeof(int) * imageSize);
    for (int i = 0; i < imageSize; i++) {
        (*returnColumnSizes)[i] = imageColSize[i];
    }

    if (newColor != image[sr][sc]) {
        paint(image, imageSize, imageColSize, sr, sc, newColor, image[sr][sc]);
    }

    return image;
}
