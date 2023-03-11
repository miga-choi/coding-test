/**
 * @param {string} s
 * @return {number}
 */
var myAtoi = function (s) {
  const regex = ['-', '+', '0', '1', '2', '3', '4', '5', '6', '7', '8', '9', '.'];
  let keep = true;
  if (s.startsWith('.')) {
    s = '0'.concat(s);
  }
  const sArray = s.trim().split('');
  if (!regex.includes(sArray[0])) {
    return 0;
  }
  const result = sArray.reduce((r, v) => {
    if (regex.includes(v) && keep) {
      r = r.concat(v);
    } else {
      keep = false;
    }
    return r;
  }, '');
  let int = parseInt(result);
  if (int < -(2 ** 31)) {
    int = -(2 ** 31);
  } else if (int > 2 ** 31 - 1) {
    int = 2 ** 31 - 1;
  } else if (!int) {
    int = 0;
  }
  return int;
};
