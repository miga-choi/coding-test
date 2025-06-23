/**
 * @param {number[]} plateFreq
 * @param {string} word
 * @return {boolean}
 */
var isCompleting = function (plateFreq, word) {
  const wordFreq = Array(26).fill(0);

  for (const char of word) {
    wordFreq[char.charCodeAt(0) - 97]++;
  }

  for (let i = 0; i < 26; i++) {
    if (wordFreq[i] < plateFreq[i]) {
      return false;
    }
  }

  return true;
};

/**
 * @param {string} licensePlate
 * @param {string[]} words
 * @return {string}
 */
var shortestCompletingWord = function (licensePlate, words) {
  const plateFreq = Array(26).fill(0);

  for (const char of licensePlate) {
    if (/^[A-Z]$/i.test(char)) {
      plateFreq[char.toLowerCase().charCodeAt(0) - 97]++;
    }
  }

  let shortestWord = "";
  let minLength = 15;

  for (const word of words) {
    const currentLength = word.length;

    if (currentLength >= minLength) {
      continue;
    }

    if (isCompleting(plateFreq, word)) {
      minLength = currentLength;
      shortestWord = word;
    }
  }

  return shortestWord;
};


// Solution
const primes = [
  2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71,
  73, 79, 83, 89, 97, 101,
];

var getCharProduct = function (plate) {
  let product = 1;

  for (const c of plate) {
    const index = c.charCodeAt(0) - 97;
    if (0 <= index && index <= 25) {
      product *= primes[index];
    }
  }

  return product;
};

var solution = function (licensePlate, words) {
  const charProduct = getCharProduct(licensePlate.toLowerCase());

  let shortest = "aaaaaaaaaaaaaaaaaaaa"; // 16 a's

  for (const word of words) {
    if (
      word.length < shortest.length &&
      getCharProduct(word) % charProduct == 0
    ) {
      shortest = word;
    }
  }

  return shortest;
};
