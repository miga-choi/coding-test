class IntersectionOfTwoArrays {
  /**
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(N)
   */
  List<int> intersection(List<int> nums1, List<int> nums2) {
    Set<int> numsSet = Set<int>();

    for (int num1 in nums1) {
      for (int num2 in nums2) {
        if (num1 == num2) {
          numsSet.add(num1);
        }
      }
    }

    return numsSet.toList();
  }


  // Solution
  /**
   * Solution 1
   *
   * Set
   *
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(N + M)
   */
  List<int> solution1(List<int> nums1, List<int> nums2) {
    final set1 = nums1.toSet();
    final result = <int>{};

    for (final x in nums2) {
      if (set1.contains(x)) result.add(x);
    }

    return result.toList();
  }

  /**
   * Solution 2
   *
   * Set
   *
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(N + M)
   */
  List<int> solution2(List<int> nums1, List<int> nums2) =>
      nums1.toSet().intersection(nums2.toSet()).toList();

  /**
   * Solution 3
   *
   * Sort + Two pointers
   *
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N * logᴺ + M * logᴹ)
   *   - Space Complexity: O(1)
   */
  List<int> solution3(List<int> nums1, List<int> nums2) {
    final a = List<int>.of(nums1)..sort();
    final b = List<int>.of(nums2)..sort();
    final res = <int>[];
    var i = 0, j = 0;

    while (i < a.length && j < b.length) {
      if (a[i] < b[j]) {
        i++;
      } else if (a[i] > b[j]) {
        j++;
      } else {
        if (res.isEmpty || res.last != a[i]) {
          res.add(a[i]);
        }
        i++;
        j++;
      }
    }

    return res;
  }

  /**
   * Solution 4
   *
   * Constraints
   *
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(1)
   */
  List<int> solution4(List<int> nums1, List<int> nums2) {
    final seen = List<bool>.filled(1001, false);
    final taken = List<bool>.filled(1001, false);

    for (final x in nums1) {
      seen[x] = true;
    }

    final res = <int>[];
    for (final x in nums2) {
      if (seen[x] && !taken[x]) {
        taken[x] = true;
        res.add(x);
      }
    }

    return res;
  }
}
