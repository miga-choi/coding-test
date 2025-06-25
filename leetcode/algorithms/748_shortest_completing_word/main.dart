class ShortestCompletingWord {
  bool isCompleting(List<int> plateFreq, String word) {
    List<int> wordFreq = List<int>.filled(26, 0);

    for (int i = 0; i < word.length; i++) {
      wordFreq[word.codeUnitAt(i) - 97]++;
    }

    for (int i = 0; i < 26; i++) {
      if (wordFreq[i] < plateFreq[i]) {
        return false;
      }
    }

    return true;
  }

  String shortestCompletingWord(String licensePlate, List<String> words) {
    List<int> plateFreq = List<int>.filled(26, 0);

    licensePlate = licensePlate.toLowerCase();

    for (int i = 0; i < licensePlate.length; i++) {
      int codeUnit = licensePlate.codeUnitAt(i) - 97;
      if (codeUnit >= 0 && codeUnit < 26) {
        plateFreq[codeUnit]++;
      }
    }

    String shortestWord = "";
    int minLength = 15;

    for (String word in words) {
      int currentLength = word.length;

      if (currentLength >= minLength) {
        continue;
      }

      if (isCompleting(plateFreq, word)) {
        minLength = currentLength;
        shortestWord = word;
      }
    }

    return shortestWord;
  }


  // Solution
  static final List<int> primes = [
    2,
    3,
    5,
    7,
    11,
    13,
    17,
    19,
    23,
    29,
    31,
    37,
    41,
    43,
    47,
    53,
    59,
    61,
    67,
    71,
    73,
    79,
    83,
    89,
    97,
    101,
  ];

  int getCharProduct(String plate) {
    int product = 1;

    for (int i = 0; i < plate.length; i++) {
      int index = plate.codeUnitAt(i) - 97;
      if (0 <= index && index <= 25) {
        product *= primes[index];
      }
    }

    return product;
  }

  String solution(String licensePlate, List<String> words) {
    int charProduct = getCharProduct(licensePlate.toLowerCase());
    String shortest = "aaaaaaaaaaaaaaaaaaaa"; // 16 a's

    for (String word in words) {
      if (word.length < shortest.length &&
          getCharProduct(word) % charProduct == 0) {
        shortest = word;
      }
    }

    return shortest;
  }
}
