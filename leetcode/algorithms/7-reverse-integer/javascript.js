/**
 * @param {number} x
 * @return {number}
 */
var reverse = function (x) {
  const xArray = x.toString().split('').reverse();

  const n = parseInt(
    xArray.reduce((s, v) => {
      if (v === '-') {
        return v.concat(s);
      }
      return s.concat(v);
    }, '')
  );

  if (n < -(2 ** 31) || n > 2 ** 31 - 1) {
    return 0;
  }

  return n;
};
