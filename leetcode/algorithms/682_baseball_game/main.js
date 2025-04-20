/**
 * @param {string[]} operations
 * @return {number}
 */
var calPoints = function (operations) {
  const scoreArray = new Array();

  for (let i = 0; i < operations.length; i++) {
    if (operations.at(i).startsWith("+")) {
      scoreArray.push(
        scoreArray.at(scoreArray.length - 2) +
          scoreArray.at(scoreArray.length - 1)
      );
    } else if (operations.at(i).startsWith("D")) {
      scoreArray.push(scoreArray.at(scoreArray.length - 1) * 2);
    } else if (operations.at(i).startsWith("C")) {
      scoreArray.pop();
    } else {
      scoreArray.push(parseInt(operations.at(i)));
    }
  }

  return scoreArray.reduce(
    (accumulator, currentValue) => accumulator + currentValue,
    0
  );
};


// Solution
let solution = (ops, s = []) => {
  for (op of ops) {
    let n = s.length;
    if (op == "+") {
      s.push(s[n - 2] + s[n - 1]);
    } else if (op == "D") {
      s.push(2 * s[n - 1]);
    } else if (op == "C") {
      s.pop();
    } else {
      s.push(+op);
    }
  }
  return _.sum(s);
};
