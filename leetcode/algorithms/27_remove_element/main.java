import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class RemoveElement {

  public int removeElement(int[] nums, int val) {
    List<Integer> newNums = new ArrayList<>();
    for (Integer num : nums) {
      if (!num.equals(val)) {
        newNums.add(num);
      }
    }
    Arrays.sort(nums);
    for (int i = 0; i < newNums.size(); i++) {
      nums[i] = newNums.get(i);
    }
    return newNums.size();
  }

  // Best Solution
  public int bestSolution(int[] nums, int val) {
    int i = 0;
    for (int j = 0; j < nums.length; j++) {
      if (nums[j] != val) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
        i++;
      }
    }
    return i;
  }
}
