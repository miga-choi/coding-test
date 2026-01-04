import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class RemoveElement {
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
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


  // Solution
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int solution(int[] nums, int val) {
    int k = 0;

    for (int i = 0; i < nums.length; i++) {
      if (nums[i] != val) {
        nums[k] = nums[i];
        k++;
      }
    }

    return k;
  }
}
