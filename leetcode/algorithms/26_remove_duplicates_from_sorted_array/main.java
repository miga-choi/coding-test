import java.util.SortedSet;
import java.util.TreeSet;

class RemoveDuplicatesFromSortedArray {
  /**
   * Two Pointers
   * - Time Complexity: O(N)
   * - Space Complexity: O(1)
   */
  public int removeDuplicates1(int[] nums) {
    int left = 0;

    for (int right = 0; right < nums.length; right++) {
      if (nums[left] != nums[right]) {
        nums[++left] = nums[right];
      }
    }

    return left + 1;
  }

  /**
   * TreeSet
   * - Time Complexity: O(?)
   * - Space Complexity: O(?)
   */
  public int removeDuplicates2(int[] nums) {
    SortedSet<Integer> set = new TreeSet<>();

    for (int num : nums) {
      set.add(num);
    }

    int i = 0;

    for (int v : set) {
      nums[i++] = v;
    }

    return i;
  }


  // Solution
  // Solution 1
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

  // Solution 2
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
