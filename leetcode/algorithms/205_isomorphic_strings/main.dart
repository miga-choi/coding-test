class RemoveLinkedListElements {
  bool isIsomorphic(String s, String t) {
    Map<String, int> sMap = Map<String, int>();
    Map<String, int> tMap = Map<String, int>();

    for (var i = 0; i < s.length; i++) {
      if (sMap[s[i]] == null && tMap[t[i]] == null) {
        sMap[s[i]] = i;
        tMap[t[i]] = i;
      } else if (sMap[s[i]] != null && tMap[t[i]] != null) {
        if (sMap[s[i]] != tMap[t[i]]) {
          return false;
        }
      } else {
        return false;
      }
    }

    return true;
  }


  // Solution
  bool solution(String s, String t) {
    Map<String, int> mapS = {};
    Map<String, int> mapT = {};
    for (int i = 0; s.length > i; i++) {
      mapS.addEntries({s[i]: i}.entries);
      mapT.addEntries({t[i]: i}.entries);
    }
    return mapS.values.join() == mapT.values.join();
  }
}
