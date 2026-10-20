class FindAllNumbersDisappearedInAnArray {
  /**
   * Auxiliary Array
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> findDisappearedNumbers(List<int> nums) {
    List<int> numArray = List<int>.filled(nums.length, 0);

    for (int num in nums) {
      numArray[num - 1] = 1;
    }

    List<int> result = List<int>.empty(growable: true);

    for (int i = 1; i <= nums.length; i++) {
      if (numArray[i - 1] == 0) {
        result.add(i);
      }
    }

    return result;
  }


  // Solution
  /**
   * Solution 1
   *
   * Negative Marking
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution1(List<int> nums) {
    for (var i = 0; i < nums.length; i++) {
      final idx = nums[i].abs() - 1;
      if (nums[idx] > 0) {
        nums[idx] = -nums[idx];
      }
    }

    final res = <int>[];
    for (var i = 0; i < nums.length; i++) {
      if (nums[i] > 0) {
        res.add(i + 1);
      }
    }

    return res;
  }

  /**
   * Solution 2
   * 
   * Boolean Array
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  List<int> solution2(List<int> nums) {
    final seen = List<bool>.filled(nums.length + 1, false);
    for (final x in nums) {
      seen[x] = true;
    }

    return [ for (var v = 1; v <= nums.length; v++) if (!seen[v]) v ];
  }

  /**
   * Solution 3
   *
   * Cyclic Sort
   *
   * Complexities:
   *   N - The Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  List<int> solution3(List<int> nums) {
    var i = 0;
    while (i < nums.length) {
      final target = nums[i] - 1;
      if (nums[i] != nums[target]) {
        final tmp = nums[i];
        nums[i] = nums[target];
        nums[target] = tmp;
      } else {
        i++;
      }
    }

    final res = <int>[];
    for (var i = 0; i < nums.length; i++) {
      if (nums[i] != i + 1) {
        res.add(i + 1);
      }
    }

    return res;
  }
}
