class Solution {

  public int strStr(String haystack, String needle) {
    if (haystack == null || haystack.equals("")) {
      return -1;
    }
    if (needle == null || needle.equals("")) {
      return 0;
    }
    return haystack.indexOf(needle, 0);
  }

  // Best Solution
  public int bestSolution(String haystack, String needle) {
    for (int i = 0;; i++) {
      for (int j = 0;; j++) {
        if (j == needle.length()) return i;
        if (i + j == haystack.length()) return -1;
        if (needle.charAt(j) != haystack.charAt(i + j)) break;
      }
    }
  }
}
