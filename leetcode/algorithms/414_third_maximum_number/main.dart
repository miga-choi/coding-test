import 'dart:collection'; // SplayTreeSet

class ThirdMaximumNumber {
  /**
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
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


  // Solution
  /**
   * Solution 1
   * 
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution1(List<int> nums) {
    int? first, second, third;

    for (final x in nums) {
      if (x == first || x == second || x == third) {
        continue;
      }

      if (first == null || x > first) {
        third = second;
        second = first;
        first = x;
      } else if (second == null || x > second) {
        third = second;
        second = x;
      } else if (third == null || x > third) {
        third = x;
      }
    }

    return third ?? first!;
  }

  /**
   * Solution 2
   * 
   * SplayTreeSet
   * 
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  int solution2(List<int> nums) {
    final top = SplayTreeSet<int>();

    for (final x in nums) {
      top.add(x);

      if (top.length > 3) {
        top.remove(top.first);
      }
    }

    return top.length == 3 ? top.first : top.last;
  }

  /**
   * Solution 3
   * 
   * Sorting
   * 
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N)
   */
  int solution3(List<int> nums) {
    final distinct = nums.toSet().toList()..sort((a, b) => b.compareTo(a));
    return distinct.length >= 3 ? distinct[2] : distinct[0];
  }
}
