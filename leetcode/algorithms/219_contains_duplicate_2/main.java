import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

class ContainsDuplicateII {
  public boolean containsNearbyDuplicate(int[] nums, int k) {
    Map<Integer, Integer> numsMap = new HashMap<Integer, Integer>();

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
  public boolean solution(int[] nums, int k) {
    Set<Integer> set = new HashSet<Integer>();
    for (int i = 0; i < nums.length; i++) {
      if (i > k) {
        set.remove(nums[i - k - 1]);
      }
      if (!set.add(nums[i])) {
        return true;
      }
    }
    return false;
  }
}
