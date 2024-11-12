class SummaryRanges {
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

  // Best Solution
  List<String> BestSolution(List<int> nums) {
    final res = <String>[];

    if (nums.isEmpty) {
      return res;
    }

    var start = nums[0];

    for (int i = 0; i < nums.length; i++) {
      if (i == nums.length - 1) {
        if (start == nums[i]) {
          res.add("$start");
        } else {
          res.add("$start->${nums[i]}");
        }
      } else {
        if (nums[i + 1] != nums[i] + 1) {
          if (start == nums[i]) {
            res.add("$start");
          } else {
            res.add("$start->${nums[i]}");
          }
          start = nums[i + 1];
        }
      }
    }

    return res;
  }
}
