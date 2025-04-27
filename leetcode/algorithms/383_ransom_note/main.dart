class RansomNote {
  bool canConstruct(String ransomNote, String magazine) {
    List<int> alphabetArray = List<int>.filled(26, 0);

    for (int c in magazine.codeUnits) {
      alphabetArray[c - 97] = alphabetArray[c - 97] + 1;
    }

    for (int c in ransomNote.codeUnits) {
      if (alphabetArray[c - 97] > 0) {
        alphabetArray[c - 97] = alphabetArray[c - 97] - 1;
      } else {
        return false;
      }
    }

    return true;
  }


  // Solution
  bool solution(String ransomNote, String magazine) {
    if (ransomNote.length > magazine.length) {
      return false;
    } else if (ransomNote == magazine) {
      return true;
    } else if (ransomNote == "") {
      return true;
    }

    Map<String, int> map = {};

    for (int i = 0; i < magazine.length; i++) {
      if (map.containsKey(magazine[i])) {
        map[magazine[i]] = map[magazine[i]]! + 1;
      } else {
        map[magazine[i]] = 1;
      }
    }

    for (int j = 0; j < ransomNote.length; j++) {
      if (map.containsKey(ransomNote[j]) && map[ransomNote[j]]! > 0) {
        map[ransomNote[j]] = map[ransomNote[j]]! - 1;
      } else {
        return false;
      }
    }

    return true;
  }
}
