class KeyboardRow {
  List<String> findWords(List<String> words) {
    const List<int> alphabetNumRow = <int>[2, 3, 3, 2, 1, 2, 2, 2, 1, 2, 2, 2, 3, 3, 1, 1, 1, 1, 2, 1, 1, 3, 1, 3, 1, 3];
    final List<String> result = List<String>.empty(growable: true);

    for (String word in words) {
      int row = alphabetNumRow[word.toLowerCase().codeUnits.first - 'a'.codeUnits.first];
      for (int i = 0; i < word.toLowerCase().codeUnits.length; i++) {
        if (alphabetNumRow[word.toLowerCase().codeUnits[i] - 'a'.codeUnits.first] == row) {
          if (i == word.toLowerCase().codeUnits.length - 1) {
            result.add(word);
          }
        } else {
          break;
        }
      }
    }

    return result;
  }

  // Solution
  List<String> solution(List<String> words) {
    List<String> output = [];
    
    String first = "qwertyuiop";
    String second = "asdfghjkl";
    String third = "zxcvbnm";

    for (String word in words) {
      String lower = word.toLowerCase();
      if (lower.split('').every((char) => first.contains(char)) ||
          lower.split('').every((char) => second.contains(char)) ||
          lower.split('').every((char) => third.contains(char))) {
        output.add(word);
      }
    }

    return output;
  }
}
