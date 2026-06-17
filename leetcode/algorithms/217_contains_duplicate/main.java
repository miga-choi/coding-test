import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class ContainsDuplicate {
  /**
   * Hash Set
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean containsDuplicate(int[] nums) {
    if (nums.length < 2) {
      return false;
    }

    Set<Integer> set = new HashSet<>();

    for (int num : nums) {
      if (set.contains(num)) {
        return true;
      } else {
        set.add(num);
      }
    }

    return false;
  }


  // Solution
  /**
   * Solution 1
   *
   * Hash Set
   *
   * Complexities:
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public boolean solution1(int[] nums) {
    Set<Integer> set = new HashSet<>();

    for (int num : nums) {
      if (!set.add(num)) {
        return true;
      }
    }

    return false;
  }

  /**
   * Solution 2
   *
   * Sort
   *
   * Complexities:
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(1)
   */
  public boolean solution2(int[] nums) {
    Arrays.sort(nums);

    for (int i = 0; i < nums.length - 1; i++) {
      if (nums[i] == nums[i + 1]) {
        return true;
      }
    }

    return false;
  }
}
