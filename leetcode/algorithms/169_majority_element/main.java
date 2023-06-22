import java.util.HashMap;
import java.util.Map;

class MajorityElement {

  public int majorityElement(int[] nums) {
    Map<Integer, Integer> numsMap = new HashMap<Integer, Integer>();

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
}
