/**
 * @param {string} s
 * @param {number} k
 * @return {string}
 */
var licenseKeyFormatting = function (s, k) {
  s = s.replaceAll("-", "");
  result = "";

  for (let i = s.length; i >= 0; i -= k) {
    if (i > k) {
      result = "-" + s.substring(i - k, i) + result;
    } else {
      result = s.substring(i - k, i) + result;
    }
  }

  return result.toUpperCase();
};



// Solution
var solution = function (s, k) {
  // Remove existing dashes and convert any lowercase letters to uppercase
  const newStr = s.replace(/-/g, "").toUpperCase();

  // Convert string to an array so we can manipulate it
  const arr = newStr.split("");

  for (let i = arr.length - 1 - k; i >= 0; i -= k) {
    // Loop through array backwards and decrement by value of K
    arr[i] = arr[i] + "-";
  }

  return arr.join("");
};
