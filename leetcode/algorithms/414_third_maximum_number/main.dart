import 'dart:math';

class ThirdMaximumNumber {
  int thirdMax(List<int> nums) {
    int first = nums.first;
    int second = -(2 << 30) - 1;
    int third = -(2 << 30) - 1;

    for (int num in nums) {
      if (num > first) {
        third = second;
        second = first;
        first = num;
      } else if (num < first && num > second) {
        third = second;
        second = num;
      } else if (num < second && num > third) {
        third = num;
      }
    }

    return third == -(2 << 30) - 1 ? first : third;
  }

  // Best Solution 1
  int bestSolution1(List<int> nums) {
    nums.sort();
    Set<int> data = nums.toSet();
    int count = data.length;
    if (data.length <= 2) {
      return data.last;
    } else {
      return data.elementAt(count - 3);
    }
  }

  // Best Solution 2
  int bestSolution2(List<int> nums) {
    const nth = 3;
    List<int> topN = <int>[];
    int minIndex = 0;
    for (int n in nums) {
      insertIntoTopN:
      if (topN.length < nth || n > topN[minIndex]) {
        for (int v in topN) {
          if (n == v) {
            // Don't insert, it's already there.
            break insertIntoTopN;
          }
        }
        if (topN.length < nth) {
          topN.add(n);
        } else {
          topN[minIndex] = n;
        }
        minIndex = _indexOfMinValue(topN);
      }
    }
    if (topN.length < nth) {
      return topN.reduce(max);
    }
    return topN[minIndex];
  }

  int _indexOfMinValue(List<int> nums) {
    if (nums.isEmpty) {
      throw ArgumentError(nums);
    }
    int result = 0;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] < nums[result]) {
        result = i;
      }
    }
    return result;
  }
}
