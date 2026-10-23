class AssignCookies {
  /**
   * Sorting + Greedy
   * 
   * Complexities:
   *   N - The Size of `g`
   *   M - The Size of `s`
   *   - Time Complexity: O(N * logᴺ + M * logᴹ)
   *   - Space Complexity: O(1)
   */
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
  /**
   * Solution 1
   * 
   * Sorting + Greedy
   * 
   * Complexities:
   *   N - The Size of `g`
   *   M - The Size of `s`
   *   - Time Complexity: O(N * logᴺ + M * logᴹ)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> g, List<int> s) {
    g.sort();
    s.sort();

    var child = 0;
    for (var cookie = 0; cookie < s.length && child < g.length; cookie++) {
      if (s[cookie] >= g[child]) {
        child++;
      }
    }

    return child;
  }

  /**
   * Solution 2
   * 
   * Sorting + Greedy
   * 
   * Complexities:
   *   N - The Size of `g`
   *   M - The Size of `s`
   *   - Time Complexity: O(N * logᴺ + M * logᴹ)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> g, List<int> s) {
    g.sort();
    s.sort();

    var cookie = s.length - 1;
    var count = 0;
    for (var child = g.length - 1; child >= 0 && cookie >= 0; child--) {
      if (s[cookie] >= g[child]) {
        count++;
        cookie--;
      }
    }

    return count;
  }
}
