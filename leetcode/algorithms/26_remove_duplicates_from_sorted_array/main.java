import java.util.SortedSet;
import java.util.TreeSet;

class RemoveDuplicatesFromSortedArray {
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
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
   * 
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N * logᴺ)
   *   - Space Complexity: O(N)
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
  /**
   * Two Pointers
   *
   * Complexities:
   *   N - Length of `nums`
   *   - Time Complexity: O(N)
   *   - Space Complexity: O(1)
   */
  public int solution(int[] nums) {
    int k = 1;

    for (int i = 1; i < nums.length; i++) {
      if (nums[i] != nums[i - 1]) {
        nums[k] = nums[i];
        k++;
      }
    }

    return k;
  }
}
