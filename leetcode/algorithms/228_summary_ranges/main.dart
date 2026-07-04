class SummaryRanges {
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  List<String> summaryRanges(List<int> nums) {
    List<String> stringList = List<String>.empty(growable: true);

    if (nums.length > 0) {
      int begin = nums.first;
      for (int i = 1; i < nums.length; i++) {
        if ((nums[i] - 1) > nums[i - 1]) {
          if (begin < nums[i - 1]) {
            stringList.add("$begin->${nums[i - 1]}");
          } else {
            stringList.add("$begin");
          }
          begin = nums[i];
        }
      }

      if (begin < nums.last) {
        stringList.add("$begin->${nums.last}");
      } else {
        stringList.add("$begin");
      }
    }

    return stringList;
  }


  // Solution
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  List<String> solution(List<int> nums) {
    List<String> result = [];

    if (nums.isEmpty) {
      return result;
    }

    int i = 0;
    int n = nums.length;

    while (i < n) {
      int start = nums[i];

      while (i + 1 < n && nums[i + 1] == nums[i] + 1) {
        i++;
      }

      if (start == nums[i]) {
        result.add("$start");
      } else {
        result.add("$start->${nums[i]}");
      }

      i++;
    }

    return result;
  }
}
