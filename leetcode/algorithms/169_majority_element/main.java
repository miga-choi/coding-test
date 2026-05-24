import java.util.HashMap;
import java.util.Map;

class MajorityElement {
  /**
   * HashMap
   *
   * Complexities:
   *   N - `numsSize`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(N)
   */
  public int majorityElement(int[] nums) {
    Map<Integer, Integer> numsMap = new HashMap<>();

    for (int i = 0; i < nums.length; i++) {
      int num = nums[i];
      int numsNum = numsMap.get(num) == null ? 0 : numsMap.get(num);

      if (numsNum == 0) {
        numsMap.put(num, 1);
      } else {
        numsMap.replace(num, numsNum + 1);
      }

      if (numsNum >= nums.length / 2) {
        return num;
      }
    }

    return 0;
  }


  // Solution
  /**
   * Boyer-Moore Voting Algorithm
   *
   * Complexities:
   *   N - `numsSize`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int solution(int[] nums) {
    int candidate = 0;
    int count = 0;

    for (int num : nums) {
      if (count == 0) {
        candidate = num;
      }

      if (num == candidate) {
        count++;
      } else {
        count--;
      }
    }

    return candidate;
  }
}
