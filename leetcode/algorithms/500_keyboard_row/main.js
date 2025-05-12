/**
 * @param {string[]} words
 * @return {string[]}
 */
var findWords = function (words) {
  const rows = ["qwertyuiop", "asdfghjkl", "zxcvbnm"];
  const result = [];

  for (let word of words) {
    let row = -1;
    for (const c of word) {
      if (rows[0].indexOf(c.toLowerCase()) >= 0) {
        if (row === -1) {
          row = 0;
        } else if (row !== 0) {
          row = -1;
          break;
        }
      } else if (rows[1].indexOf(c.toLowerCase()) >= 0) {
        if (row === -1) {
          row = 1;
        } else if (row !== 1) {
          row = -1;
          break;
        }
      } else if (rows[2].indexOf(c.toLowerCase()) >= 0) {
        if (row === -1) {
          row = 2;
        } else if (row !== 2) {
          row = -1;
          break;
        }
      }
    }
    if (row > -1) {
      result.push(word);
    }
  }

  return result;
};


// Solution
var solution = function (words) {
  return words.filter((w) => {
    // remove word from array if it fails matching all three rows
    if (
      !/^[qwertyuiop]*$/i.test(w) &&
      !/^[asdfghjkl]*$/i.test(w) &&
      !/^[zxcvbnm]*$/i.test(w)
    ) {
      return false;
    }

    return true;
  });
};
