/**
 * @param {string} s
 * @return {string}
 */
var reverseVowels = function (s) {
  const vowels = ["A", "E", "I", "O", "U", "a", "e", "i", "o", "u"];
  const vowelStack = [];
  let result = "";
  for (const c of s) {
    if (vowels.includes(c)) {
      vowelStack.push(c);
    }
  }
  for (let i = 0; i < s.length; i++) {
    if (vowels.includes(s[i])) {
      result += vowelStack.pop();
    } else {
      result += s[i];
    }
  }
  return result;
};


// Best Solution
var bestSolution1 = function (s) {
  const VOWELS = { a: 1, e: 1, i: 1, o: 1, u: 1, A: 1, E: 1, I: 1, O: 1, U: 1 };
  const arr = s.split("");
  let i = 0,
    j = arr.length - 1;
  while (i < j) {
    if (VOWELS[arr[i]] && VOWELS[arr[j]]) {
      [arr[i], arr[j]] = [arr[j], arr[i]];
      i++;
      j--;
    } else if (VOWELS[arr[i]]) {
      j--;
    } else {
      i++;
    }
  }
  return arr.join("");
};

var bestSolution2 = function (s) {
  const vowels = s.split("").filter((a) => /[aeiou]/i.test(a));
  return s
    .split(/[aeiou]/i)
    .reduce((res, a) => res + a + (vowels.pop() || ""), "");
};
