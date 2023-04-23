import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class Solution {

  public int removeDuplicates(int[] nums) {
    Set<Integer> numsSet = new HashSet<Integer>();
    for (int num : nums) {
      numsSet.add(num);
    }
    Object[] numsArray = numsSet.stream().toArray();
    Arrays.sort(numsArray);
    for (int i = 0; i < numsArray.length; i++) {
      nums[i] = (int) numsArray[i];
    }
    return numsArray.length;
  }

  // Best Solution
  public int bestSolution(int[] nums) {
    int i = nums.length > 0 ? 1 : 0;
    for (int n : nums) {
      if (n > nums[i - 1]) {
        nums[i++] = n;
      }
    }
    return i;
  }
}
