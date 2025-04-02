/**
 * @param {string} moves
 * @return {boolean}
 */
var judgeCircle = function (moves) {
  let landscape = 0;
  let portrait = 0;

  for (const c of moves) {
    switch (c) {
      case "U":
        portrait++;
        break;
      case "D":
        portrait--;
        break;
      case "R":
        landscape++;
        break;
      case "L":
        landscape--;
        break;
    }
  }

  return !landscape && !portrait;
};

// Solution
var solution = function (moves) {
  let x = 0, y = 0;
  for (let move of moves) {
    switch (move) {
      case "U":
        y++;
        break;
      case "D":
        y--;
        break;
      case "L":
        x--;
        break;
      case "R":
        x++;
        break;
    }
  }
  return x === 0 && y === 0;
};
