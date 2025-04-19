public class RemoveElement {
    public int RemoveElement(int[] nums, int val) {
        int i = 0;
        for (int j = 0; j < nums.Length; j++) {
            if (nums[j] != val) {
                int temp = nums[i];
                nums[i] = nums[j];
                nums[j] = temp;
                i++;
            }
        }
        return i;
    }


    // Solution
    // Solution 1:
    public int solution1(int[] nums, int val) {
        int result = 0;
        foreach (var item in nums) {
            if (item != val) {
                nums[result] = item;
                result++;
            }
        }
        return result;
    }

    // Solution 2:
    public int solution2(int[] nums, int val) {
        var j = 0;
        for (var i = 0; i < nums.length; i++) {
            if (nums[i] != val) {
                nums[j++] = nums[i];
            }
        }
        return j;
    }
}
