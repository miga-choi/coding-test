/**
 * @param {string} s
 * @return {string}
 */
var toLowerCase = function (s) {
  let result = "";

  for (const c of s) {
    const code = c.charCodeAt(0);
    if (code >= 65 && code <= 90) {
      result += String.fromCharCode(code + 32);
    } else {
      result += c;
    }
  }

  return result;
};


// Solution
var solution = function (s) {
  let ans = "";

  for (let c of s) {
    let n = c.charCodeAt();
    ans += n > 64 && n < 91 ? String.fromCharCode(n + 32) : c;
  }

  return ans;
};
