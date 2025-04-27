class FirstUniqueCharacterInAString {
  // List
  int firstUniqChar1(String s) {
    List<int> alphabetNumArray = List<int>.filled(26, 0);
    List<String> sArray = s.split("");

    for (String c in sArray) {
      alphabetNumArray[c.codeUnitAt(0) - 'a'.codeUnitAt(0)] += 1;
    }

    for (int i = 0; i < sArray.length; i++) {
      if (alphabetNumArray[sArray[i].codeUnitAt(0) - 'a'.codeUnitAt(0)] == 1) {
        return i;
      }
    }

    return -1;
  }

  // Map
  int firstUniqChar2(String s) {
    Map<String, int> alphabetNumMap = Map<String, int>.new();
    List<String> sArray = s.split("");

    for (String c in sArray) {
      if (alphabetNumMap[c] == null) {
        alphabetNumMap[c] = 0;
      } else {
        alphabetNumMap[c] = alphabetNumMap[c]! + 1;
      }
    }

    for (int i = 0; i < sArray.length; i++) {
      if (alphabetNumMap[sArray[i]] == 1) {
        return i;
      }
    }

    return -1;
  }


  // Solution
  int solution(String s) {
    final inputArr = s.split('');

    for (final value in inputArr) {
      if (inputArr.indexOf(value) == inputArr.lastIndexOf(value)) {
        return inputArr.indexOf(value);
      }
    }

    return -1;
  }
}
