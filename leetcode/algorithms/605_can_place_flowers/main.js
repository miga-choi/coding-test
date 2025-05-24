/**
 * @param {number[]} flowerbed
 * @param {number} n
 * @return {boolean}
 */
var canPlaceFlowers = function (flowerbed, n) {
  let canPlant = 0;

  for (let i = 0; i < flowerbed.length; i++) {
    if (i === 0) {
      if (!flowerbed[i] && !flowerbed[i + 1]) {
        flowerbed[i] = 1;
        canPlant++;
      }
    } else if (i === flowerbed.length - 1) {
      if (!flowerbed[i - 1] && !flowerbed[i]) {
        flowerbed[i] = 1;
        canPlant++;
      }
    } else {
      if (!flowerbed[i - 1] && !flowerbed[i] && !flowerbed[i + 1]) {
        flowerbed[i] = 1;
        canPlant++;
      }
    }
  }

  return canPlant >= n;
};


// Solution
// Solution 1
var solution1 = function (flowerbed, n) {
  let current = 0;
  const size = flowerbed.length;
  for (var i = 0; i <= size; i++) {
    if (i < size && flowerbed[i] == 0) {
      current++;
      if (i == 0) {
        current++;
      }
      if (i == size - 1) {
        current++;
      }
    } else {
      n -= Math.trunc((current - 1) / 2);
      if (n <= 0) {
        return true;
      }
      current = 0;
    }
  }
  return false;
};

// Solution 2
var solution2 = function (flowerbed, n) {
  for (let i = 0; i < flowerbed.length && n !== 0; i++) {
    if (flowerbed[i] === 0 && flowerbed[i - 1] !== 1 && flowerbed[i + 1] !== 1) {
      n--;
      i++;
    }
  }
  return n === 0;
};
