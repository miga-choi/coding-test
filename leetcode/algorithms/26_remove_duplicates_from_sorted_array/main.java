import java.util.Arrays;
import java.util.HashSet;
import java.util.Set;

class RemoveDuplicatesFromSortedArray {
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


  // Solution
  // Solution 1:
  public int solution1(int[] nums) {
    int j = 1;
    for (int i = 1; i < nums.length; i++) {
      if (nums[i] != nums[i - 1]) {
        nums[j] = nums[i];
        j++;
      }
    }
    return j;
  }

  // Solution 2:
  public int solution2(int[] nums) {
    int i = nums.length > 0 ? 1 : 0;
    for (int n : nums) {
      if (n > nums[i - 1]) {
        nums[i++] = n;
      }
    }
    return i;
  }
}
