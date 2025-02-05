class ReverseStringII {
  void swap(List<String> sArray, int l, int r) {
    while (l < r) {
      String temp = sArray[l];
      sArray[l++] = sArray[r];
      sArray[r--] = temp;
    }
  }

  String reverseStr(String s, int k) {
    int n = s.length;
    int i = 0;
    List<String> sArray = s.split("");

    while (i < n) {
      int j = i + k - 1 < n - 1 ? i + k - 1 : n - 1;
      swap(sArray, i, j);
      i += 2 * k;
    }

    return sArray.join();
  }

  // Solution
  String solution(String s, int k) {
    List<String> result = s.split('');

    for (int i = 0; i < s.length; i += 2 * k) {
      int start = i;
      int end = (i + k - 1 < s.length) ? i + k - 1 : s.length - 1;
      while (start <= end) {
        String temp = result[start];
        result[start] = result[end];
        result[end] = temp;
        start++;
        end--;
      }
    }

    return result.join();
  }
}
