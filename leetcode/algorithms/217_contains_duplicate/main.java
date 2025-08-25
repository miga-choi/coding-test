import java.util.HashSet;
import java.util.Set;

class ContainsDuplicate {
  /**
   * Set
   * - Time Complexity: O(N)
   * - Space Complexity: O(N)
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
}
