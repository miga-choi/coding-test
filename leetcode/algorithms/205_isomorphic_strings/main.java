class IsomorphicStrings {
  public boolean isIsomorphic(String s, String t) {
    if (s.length() != t.length()) {
      return false;
    }

    int[] sMap = new int[50000];
    int[] tMap = new int[50000];

    for (int i = 0; i < s.length(); i++) {
      if (sMap[s.charAt(i)] != tMap[t.charAt(i)]) {
        return false;
      }
      sMap[s.charAt(i)] = i + 1;
      tMap[t.charAt(i)] = i + 1;
    }

    return true;
  }


  // Solution
  public boolean solution(String s, String t) {
    int map1[] = new int[200];
    int map2[] = new int[200];

    if (s.length() != t.length()) {
      return false;
    }

    for (int i = 0; i < s.length(); i++) {
      if (map1[s.charAt(i)] != map2[t.charAt(i)]) {
        return false;
      }

      map1[s.charAt(i)] = i + 1;
      map2[t.charAt(i)] = i + 1;
    }
    return true;
  }
}
