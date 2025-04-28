class AssignCookies {
  int findContentChildren(List<int> g, List<int> s) {
    g.sort((int a, int b) => a - b);
    s.sort((int a, int b) => a - b);

    int i = 0;

    for (int j = 0; i < g.length && j < s.length; j++) {
      if (g[i] <= s[j]) {
        i++;
      }
    }

    return i;
  }


  // Solution
  int solution(List<int> g, List<int> s) {
    g.sort();
    s.sort();

    int ind = 0;
    int cookiesind = 0;

    while (ind < g.length && cookiesind < s.length) {
      if (s[cookiesind] >= g[ind]) {
        ind++;
      }
      cookiesind++;
    }

    return ind;
  }
}
