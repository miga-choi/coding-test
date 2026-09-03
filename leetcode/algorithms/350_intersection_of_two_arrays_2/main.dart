class IntersectionOfTwoArraysII {
  /**
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N * M)
   *   - Space Complexity: O(N + M)
   */
  List<int> intersect(List<int> nums1, List<int> nums2) {
    List<int> result = List<int>.empty(growable: true);

    for (int i = 0; i < nums1.length; i++) {
      for (int j = 0; j < nums2.length; j++) {
        if (nums1[i] != -1 && nums1[i] == nums2[j]) {
          result.add(nums1[i]);
          nums1[i] = -1;
          nums2[j] = -1;
        }
      }
    }

    return result;
  }


  // Solution
  /**
   * Map
   *
   * Complexities:
   *   N - The size of `nums1`
   *   M - The size of `nums2`
   *   - Time Complexity: O(N + M)
   *   - Space Complexity: O(min(N, M))
   */
  List<int> solution(List<int> nums1, List<int> nums2) {
    if (nums1.length > nums2.length) {
      return intersect(nums2, nums1);
    }

    final counts = <int, int>{};
    for (final x in nums1) {
      counts.update(x, (v) => v + 1, ifAbsent: () => 1);
    }

    final res = <int>[];
    for (final x in nums2) {
      final c = counts[x];
      if (c != null && c > 0) {
        res.add(x);
        counts[x] = c - 1;
      }
    }

    return res;
  }
}
