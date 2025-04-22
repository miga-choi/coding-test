class ValidAnagram {
  bool isAnagram(String s, String t) {
    if (s.length != t.length) {
      return false;
    }

    for (String c in s.split('')) {
      t = t.replaceFirst(c, '');
    }

    return t.isEmpty;
  }


  // Solution
  // Solution 1
  bool solution1(String s, String t) {
    List<String> s1 = s.split('');
    List<String> s2 = t.split('');
    s1.sort();
    s2.sort();
    bool result = true;
    if (s1.length != s2.length) {
      result = false;
    } else {
      for (int i = 0; i < s1.length; i++) {
        if (s1[i] != s2[i]) {
          result = false;
          break;
        }
      }
    }
    return result;
  }

  // Solution 2
  bool solution2(String s, String t) {
    if (s.length != t.length) {
      return false;
    }
    var sortedS = (s.split('')..sort()).join('');
    var sortedT = (t.split('')..sort()).join('');
    return sortedT == sortedS;
  }
}
