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
  // Best Solution 1:
  public int bestSolution1(int[] nums, int val) {
    int index = 0;
    for (int i = 0; i < nums.length; i++) {
      if (nums[i] != val) {
        nums[index] = nums[i];
        index++;
      }
    }
    return index;
  }

  // Best Solution 2:
  public int bestSolution2(int[] nums, int val) {
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

  // Best Solution 3:
  public int bestSolution3(int[] nums, int val) {
    int l = nums.length;
    for (int i = 0; i < l; i++) {
      if (nums[i] == val) {
        nums[i--] = nums[l-- - 1];
      }
    }
    return l;
  }
}
