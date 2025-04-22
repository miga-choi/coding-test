import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;

class ContainsDuplicate {
  public boolean containsDuplicate(int[] nums) {
    Map<Integer, Boolean> numsMap = new HashMap<Integer, Boolean>();
    for (int i = 0; i < nums.length; i++) {
      if (numsMap.containsKey(nums[i])) {
        return true;
      }
      numsMap.put(nums[i], true);
    }
    return false;
  }


  // Solution
  // Solution 1
  public boolean solution1(int[] nums) {
    // Create a hashset...
    HashSet<Integer> hset = new HashSet<Integer>();

    // Traverse all the elements through the loop...
    for (int idx = 0; idx < nums.length; idx++) {
      // Searches hashset. if present, it contains duplicate...
      if (hset.contains(nums[idx])) {
        return true;
      }

      // if not present it will update hashset...
      hset.add(nums[idx]);
    }

    // Otherwise return false...
    return false;
  }

  // Solution 2
  public boolean solution2(int[] nums) {
    // Base case...
    if (nums == null || nums.length == 0) {
      return false;
    }

    // Create a hashset...
    HashSet<Integer> hset = new HashSet<Integer>();

    // Traverse all the elements through the loop...
    for (int idx : nums) {
      // If it contains duplicate...
      if (!hset.add(idx)) {
        return true;
      }
    }

    // Otherwise return false...
    return false;
  }
}
