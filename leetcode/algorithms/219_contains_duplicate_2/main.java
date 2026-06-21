import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class ContainsDuplicateII {
  /**
   * Hash Map
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean containsNearbyDuplicate(int[] nums, int k) {
    Map<Integer, Integer> numsMap = new HashMap<>();

    for (int i = 0; i < nums.length; i++) {
      if (numsMap.get(nums[i]) != null) {
        if (Math.abs(i - numsMap.get(nums[i])) <= k) {
          return true;
        }
      }
      numsMap.put(nums[i], i);
    }

    return false;
  }


  // Solution
  /**
   * Solution 1
   *
   * Sliding Window + Hash Set
   *
   * Complexities:
   *   N - Size of `nums`
   *   K - `k`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(min(N, K))
   */
  public boolean solution1(int[] nums, int k) {
    Set<Integer> window = new HashSet<>();

    for (int i = 0; i < nums.length; i++) {
      if (i > k) {
        window.remove(nums[i - k - 1]);
      }

      if (!window.add(nums[i])) {
        return true;
      }
    }

    return false;
  }

  /**
   * Solution 2
   *
   * Hash Map
   *
   * Complexities:
   *   N - Size of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean solution2(int[] nums, int k) {
    Map<Integer, Integer> map = new HashMap<>();

    for (int i = 0; i < nums.length; i++) {
      if (map.containsKey(nums[i])) {
        int lastIndex = map.get(nums[i]);
        if (i - lastIndex <= k) {
          return true;
        }
      }
      map.put(nums[i], i);
    }

    return false;
  }
}
