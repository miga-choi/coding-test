/**
 * @param {string} s
 * @return {boolean}
 */
var checkRecord = function (s) {
  if (s.split("").filter((v) => v === "A").length > 1) {
    return false;
  }

  for (let i = 0; i < s.length; i++) {
    if (i > 1 && s[i] === "L" && s[i - 1] === "L" && s[i - 2] === "L") {
      return false;
    }
  }

  return true;
};


// Solution
var solution = function (s) {
  let map = new Map();

  for (let i = 0; i < s.length; i++) {
    if (s[i] === "A") {
      map.set(s[i], map.get(s[i]) === undefined ? 1 : map.get(s[i]) + 1);
      if (map.get(s[i]) >= 2) return false;
    } else if (s[i] === "L" && s[i + 1] === "L" && s[i + 2] === "L") {
      return false;
    }
  }

  return true;
};
