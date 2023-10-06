import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

class FindAllNumbersDisappearedInAnArray {
    public List<Integer> findDisappearedNumbers(int[] nums) {
        List<Integer> result = new ArrayList<Integer>();
        int length = nums.length;
        nums = Arrays.stream(nums).distinct().sorted().toArray();
        int count = 0;
        for (int i = 1; i <= length; i++) {
            if (count >= nums.length - 1) {
                result.add(i);
                continue;
            }
            if (nums[count] != i) {
                result.add(i);
            } else {
                count++;
            }
        }
        return result;
    }


    // Best Solution
    public List<Integer> bestSolution(int[] nums) {
        List<Integer> list = new ArrayList<>();
        int idx = -1;
        for (int i = 0; i < nums.length; i++) {
            if (nums[i] < 0) {
                idx = nums[i] * -1 - 1;
            } else {
                idx = nums[i] - 1;
            }

            if (nums[idx] > 0) {
                nums[idx] = -nums[idx];
            }

        }

        for (int i = 0; i < nums.length; i++) {
            if (nums[i] > 0) {
                list.add(i + 1);
            }
        }

        return list;
    }
}